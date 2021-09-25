const Toast = Swal.mixin({
    toast: true,
    position: 'top-end',
    showConfirmButton: false,
    timer: 3000
});
$(function() {
    $.ajaxSetup({
        headers: {
            'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
        }
    });
    
    $.ajax({
		url: url,
	}).done( function(data) {		
        t = $('#source-table').DataTable({
			data: data.sources,
			columns: [
                {data: null, title: '#', width: '10%'},
                {
                    data: 'pathfile',
                    title: 'Name',
                    className: 'sourcename',
                    createdCell: function (cell, cellData, rowData, rowIndex, colIndex) {
                        $(cell).attr('data-row', rowData.source_str);
                        $(cell).attr('data-toggle', 'modal');
                        $(cell).attr('data-target', '#sourcecontent-modal');
                        if (cellData == '') {
                            $(cell).cell.data(rowData.mask)
                        }
                    }
                }
            ]
		})

		t.on( 'order.dt search.dt', function () {
			t.column(0, {search:'applied', order:'applied'}).nodes().each( function (cell, i) {
				cell.innerHTML = i+1;
			} );
		} ).draw()
        if (data.project_status !== undefined){
            console.log((data.project_status !== 'undefined'));
            project_status_span = getStatusLabel(data.project_status)
            var project_detail = `${data.project_name} - <small>${project_status_span}</small>`
            $("#project-detail").html(project_detail)
            $("#project_name").text(data.project_name)
            metrics = data.metrics
            if (metrics.length > 0)  {
                for (metric of metrics) {
                    metric_name = metric['name']
                    $("#"+metric_name).prop("disabled", false)
                    $("#"+metric_name).val(metric['threshold']  * 100)
                    $("#"+metric_name+"_check").prop("checked", true)
                }
            }
            $.ajax({
                type: "GET",
                contentType: 'application/json',
                url: "/api/project/"+  project_id + "/status",
                success: function (data) {
                    // console.log('wqw')
                    project_status = data['project_status']
                    if (project_status == checked) {
                        $("#run").removeClass("btn-primary")
                        $("#run").addClass("btn-danger")
                        $("#run").text("Rerun")
                        result = $("<button>", {"class": "btn btn-default", "id":"result-btn"})
                        a = $("<a>", {"href":"/project/"+project_id+"/results", "target": "_blank"})
                        a.text("Result")
                        result.append(a)
                        $(".card-footer").append(result)
                    } else if (project_status == running) {
                        var source = new EventSource('/project/'+project_id+'/status/stream');
                        source.onmessage = function(event) {
                            console.log(event.data);
                            if (event.data == checked) {
                                $("#run").removeClass("btn-primary")
                                $("#run").addClass("btn-danger")
                                $("#run").text("Rerun")
                                source.close()
                                location.reload()
                            }
                        }
                        result = $("<button>", {"class": "btn btn-default", "id":"result-btn"})
                        a = $("<a>", {"href":"/contests/"+contest_id+"/results", "target": "_blank"})
                        a.text("Result")
                        result.append(a)
                        $(".card-footer").append(result)
                        $("#run").text("Running")
                        $("#run").prop("disabled", true)
                    }
                    // location.reload();
                },
                error: function (data) {
                    // console.log("123")
                    Toast.fire({
                        icon: 'error',
                        // console.log("qwqw"),
                        title: data.responseText
                    })
                }
            });
        
        }
		
	})

    $("#project-run").submit(function(e){
        e.preventDefault(); // avoid to execute the actual submit of the form.
        $("#result-btn").remove()
        var form = $(this);
        var list_operator = form.serializeArray()
        if (list_operator.length > 0) {
            var send_data = []
            list_operator.forEach(element => {
                var temp = {
                    'name': element['name'],
                    'threshold': element['value']/100
                }
                send_data.push(temp)
            });
            var data_form = {"metrics": send_data}
            $.ajax({
                type: "POST",
                url: "/api/project/"+project_id+"/run",
                contentType: 'application/json',
                data: JSON.stringify(data_form),
                success: function(data)
                {   
                    $("#run").prop("disabled", true)
                    $("#run").text("Running...")
                    result = $("<button>", {"class": "btn btn-default", "id":"result-btn"})
                    a = $("<a>", {"href":"/project/"+project_id+"/results", "target": "_blank"})
                    a.text("Result")
                    result.append(a)
                    $(".card-footer").append(result)
                    var source = new EventSource('/project/'+project_id+'/status/stream');
                    source.onmessage = function(event) {
                        console.log(event.data);
                        if (event.data == checked) {
                            $("#run").removeClass("btn-primary")
                            $("#run").addClass("btn-danger")
                            $("#run").text("Rerun")
                            source.close()
                            location.reload()
                        }
                    }
                },
                error: function(data)
                {
                    alert("error!");
                }
            });
            // location.reload()
        } else {
            Toast.fire({
                icon: 'warning',
                title: 'Please select metrics first!'
            })
        }
    })

    $("#source-table").on("click", ".sourcename", function(){
        $("#source-content").empty()
        var data = $(this).attr("data-row")
        var title = $(this).text()
        $("#title").text(title)
        $("#source-content").text(data)
        hljs.highlightAll();
    })
});

function createSource() {
    const form = document.createElement('form')
    const input = document.createElement('input')
    const file = document.createElement('input')
    const submit = document.createElement('input')
    const row = document.createElement('div')
    const col10 = document.createElement('div')
    const col2 = document.createElement('div')


    row.className = "form-group row"
    col10.className = "col-sm-10"
    col2.className = "col-sm-2"

    input.className = "form-control"
    input.name = "mask"
    input.style = "width: 50%;"
    input.placeholder = "Enter file name"

    file.name = "file"
    file.type = "file"

    submit.type = 'submit'
    submit.className = 'btn btn-primary'
    submit.style = "float: right;"
    submit.name = 'submit'
    submit.value = 'Submit'

    col10.appendChild(input)
    col10.append(file)
    col2.appendChild(submit)

    row.appendChild(col10)
    row.appendChild(col2)

    form.appendChild(row)

    link = document.getElementById('create-source').remove()
    
    document.getElementById('source-name').appendChild(form)
}