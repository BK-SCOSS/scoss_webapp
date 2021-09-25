params = new URL(document.getElementById("token").src).searchParams;
var token = params.get('token')
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

    // $('#source-table').DataTable();
    $.ajax({
		type: "GET",
		contentType: 'application/json',
		url: "/api/problems/"+ problem_id + "/status",
		headers: {
			Authorization: 'Bearer '+token
		},
		success: function (data) {
            // console.log('wqw')
            problem_status = data['problem_status']
            if (problem_status == checked || problem_status == failed) {
                $("#run").removeClass("btn-primary")
                $("#run").addClass("btn-danger")
                $("#run").text("Rerun")
            } else if (problem_status == running || problem_status == waiting) {
                $("#run").text("Running")
				$("#run").prop("disabled", true)
                var source = new EventSource('/problems/' + problem_id + '/status');
                source.onmessage = function(event) {
                    if (event.data == checked || event.data == failed) {
                        $("#run").removeClass("btn-primary")
                        $("#run").addClass("btn-danger")
                        $("#run").text("Rerun")
                        source.close()
			            location.reload();
                    }
                }
                // $("#run").text("Running")
                // $("#run").prop("disabled", true)
            }
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
    // $.get("/api/problems/"+ problem_id + "/status", function(data){
	// 	problem_status = data['problem_status']
	// 	if (problem_status == checked) {
    //         $.get("/api/problems/"+ problem_id + "/results", function(data){
    //             // if (data['results'].length > 0) {
                   
    //             // }
    //             create_result(data)
    //             $("#run").removeClass("btn-primary")
    //             $("#run").addClass("btn-danger")
    //             $("#run").text("Rerun")
    //         })
	// 	} else if (problem_status == running) {
    //         var source = new EventSource('/problems/' + problem_id + '/status');
	// 		source.onmessage = function(event) {
	// 			if (event.data == checked) {
	// 				$("#run").removeClass("btn-primary")
    //                 $("#run").addClass("btn-danger")
    //                 $("#run").text("Rerun")
	// 				source.close()
	// 			}
	// 		}
	// 		$("#run").text("Running")
	// 		$("#run").prop("disabled", true)
	// 	}
	// })

    $("#problem-run").submit(function(e){
        e.preventDefault(); // avoid to execute the actual submit of the form.
        $("#result").remove()

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
                url: "/api/problems/"+ problem_id + "/run",
                contentType: 'application/json',
                headers: {
                    Authorization: 'Bearer '+token
                },
                data: JSON.stringify(data_form),
                success: function()
                {   
                    $("#run").prop("disabled", true)
                    $("#run").text("Running...")
                    var source = new EventSource('/problems/' + problem_id + '/status');
                    source.onmessage = function(event) {
                        if (event.data == checked || event.data == failed) {
                            source.close()
                            // $.get("/api/problems/"+ problem_id+"/results", function(data){
                            // if (data['results'].length > 0) {
                            location.reload()
                            // } else {
                            //     Toast.fire({
                            //         icon: 'error',
                            //         title: 'No matches found!'
                            //     })
                            //     $("#run").empty()
                            //     $("#run").text("Run")
                            //     $("#run").removeAttr("disabled")
                            // }
                            // });
                        }
                    }
                },
                error: function(data)
                {
                    alert(data.responseText)
                }
            });
        } else {
            Toast.fire({
                icon: 'warning',
                title: 'Please select metrics first!'
            })
        }
        setTimeout(function(){ 
			location.reload();
		}, 1000);  
    })

    $(".sourcename").click(function(){
        $("#source-content").empty()
        var data = $(this).attr("data-row")
        var title = $(this).text()
        $("#title").text(title)
        $("#source-content").text(data)
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

$(document).on("click","#delete-all",function(){
    Swal.fire({
      title: 'Are you sure?',
      text: "You won't be able to revert this!",
      icon: 'warning',
      showCancelButton: true,
      confirmButtonColor: '#3085d6',
      cancelButtonColor: '#d33',
      confirmButtonText: 'Delete'
      }).then((result) => {
          if (result.isConfirmed) {
              $.ajax({
                    type: "DELETE",
                    contentType: 'application/json',
                    url: '/api/problems/'+problem_id+'/sources/delete_all',
                    headers: {
                    Authorization: 'Bearer '+token
                    },
                    success: function () {
                        location.reload();
                    },
                    error: function (data) {
                        Toast.fire({
                            icon: 'error',
                            title: data.responseText
                        })
                    }
              });
          }
      })
  });