$(function() {
    $.ajaxSetup({
        headers: {
            'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
        }
    });

    const Toast = Swal.mixin({
        toast: true,
        position: 'top-end',
        showConfirmButton: false,
        timer: 3000
    });

    $.get("/api/problems/"+ problem_id + "/status", function(data){
		problem_status = data['problem_status']
		if (problem_status == "checked") {
            $.get("/api/problems/"+ problem_id + "/results", function(data){
                create_result(data)
                $("#run").text("Rerun")
            })
		} else if (problem_status == 'running') {
			$("#run").text("Running")
			$("#run").prop("disabled", true)
		}
	})

    function create_row_result(score_metric, a) {
        td = $("<td>")
        C = parseFloat(score_metric)*255
        R = parseInt(C)
        G = 0
        B = 0
        span = $("<span>", {"style": `color:rgb(${R}, ${G}, ${B});`})
        span.text((score_metric * 100).toFixed(2) + "%")
        a.append(span)
        td.append(a)
        item.append(td)
    }

    function create_result(data) {
        var heads = []
        heads.push('source1')
        heads.push('source2')
        for(metric in data['results'][0]['scores']) {
            if (metric == 'mean') {
                continue
            }
            heads.push(metric)
        }
        heads.push('mean')

        row = $("<div>", {id: "result", "class": "row"})
        col = $("<div>", {"class": "col-12"})
        card = $("<div>", {"class": "card"})
        card_header = $("<div>", {"class": "card-header"})
        card_body = $("<div>", {"class": "card-body table-responsive p-0"})
        table = $("<table>", {"id": "usersTable", "class": "table table-hover table-bordered"})
        header = $("<tr>")
        
        for (head in heads) {
            header.append("<th>" + heads[head] + "<i class='fa fa-sort'></i></th>")
        }

        tbody = $("<tbody>")
        tbody.append(header)
        
        links = data['results']
        for (link of links) {
            source1 = link['source1']
            source2 = link['source2']
            item = $("<tr>", {"class": "item"})
            item.append("<td>" + source1 + "</a></td>")
            item.append("<td>" + source2 + "</a></td>")
            for (metric in link['scores']) {
                if (metric == 'mean') {
                    continue
                }
                a = $("<a>", {"href": `/problems/${problem_id}/compare?source1=${source1}&source2=${source2}&metrics=${metric}`, 
                    "target": "_blank"})
                create_row_result(link['scores'][metric], a)
            }
            create_row_result(link['scores']['mean'], $("<a>"))
            tbody.append(item)
        }
        table.append(tbody)
        card_body.append(table)
        card_header.append("<h3 class='card-title'>Result</h3>")
        card.append(card_header)
        card.append(card_body)
        col.append(card)
        row.append(col)
        $(".content .container").append(row)
    }

    $("#problem-run").submit(function(e){
        e.preventDefault(); // avoid to execute the actual submit of the form.
        $("#result").remove()

        var form = $(this);
        var list_operator = form.serializeArray()
        console.log(list_operator)
        if (list_operator.length > 0) {
            var send_data = []
            list_operator.forEach(element => {
                var temp = {
                    'name': element['name'],
                    'threshold': element['value']/100
                }
                send_data.push(temp)
            });
            var data_form = {'metrics': send_data}
            $.ajax({
                type: "POST",
                url: "/api/problems/"+ problem_id + "/run",
                contentType: 'application/json',
                data: JSON.stringify(data_form),
                success: function()
                {   
                    $("#run").prop("disabled", true)
                    $("#run").text("Running...")
                    var source = new EventSource('/problems/' + problem_id + '/status');
                    source.onmessage = function(event) {
                        if (event.data == 'checked') {
                            source.close()
                            $.get("/api/problems/"+ problem_id+"/results", function(data){
                                if (data['results'].length > 0) {
                                    $("#run").empty()
                                    $("#run").text("Run")
                                    $("#run").removeAttr("disabled")
                                    create_result(data)
                                } else {
                                    Toast.fire({
										icon: 'error',
										title: 'Threre is no result'
									})
									$("#run").empty()
									$("#run").text("Run")
									$("#run").removeAttr("disabled")
                                }
                            });
                        }
                    }
                },
                error: function(data)
                {
                    alert(data['error'])
                }
            });
        } else {
            Toast.fire({
                icon: 'warning',
                title: 'Please select metrics first!'
            })
        }
    })

    $(".sourcename").click(function(){
        $("#source-content").empty()
        var data = $(this).attr("data-row")
        var title = $(this).text()
        $("#title").text(title)
        $("#source-content").text(data)
    })
});

document.getElementById('countCheckBox').onchange = function() {
    document.getElementById('countOperator').disabled = !this.checked;
};

document.getElementById('setCheckBox').onchange = function() {
    document.getElementById('setOperator').disabled = !this.checked;
};

document.getElementById('hashCheckBox').onchange = function() {
    document.getElementById('hashOperator').disabled = !this.checked;
};

document.getElementById('smossCheckBox').onchange = function() {
    document.getElementById('smossMetric').disabled = !this.checked;
};

function createSource() {
    const form = document.createElement('form')
    const input = document.createElement('input')
    const file = document.createElement('input')
    const submit = document.createElement('input')
    const row = document.createElement('div')
    const col10 = document.createElement('div')
    const col2 = document.createElement('div')

    form.method = "POST"
    form.action = "/problems/"+problem_id+"/add_file"
    form.className = "form-horizontal"
    form.enctype = "multipart/form-data"

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