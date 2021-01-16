$(document).ready(function() {
	$.ajaxSetup({
	  headers: {
		'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
	  }
	});
	
	const Toast = Swal.mixin({
		toast: true,
		position: 'top-end',
		showConfirmButton: false,
		timer: 5000
	})

	function updateBtnStatus() {
		$("#run").text("Rerun")
		$("#run").removeAttr("disabled")
		$("#run").removeClass("btn-primary")
		$("#run").addClass("btn-danger")
		result = $("<button>", {"class": "btn btn-default", "id":"result-btn"})
		a = $("<a>", {"href":"/contests/"+contest_id+"/results", "target": "_blank"})
		a.text("Result")
		result.append(a)
		$(".card-footer").append(result)
	}

	$.get("/api/contests/"+ contest_id + "/status", function(data){
		contest_status = data['contest_status']
		if (contest_status == checked) {
			updateBtnStatus()
		} else if (contest_status == running) {
			$("#run").text("Running")
			$("#run").prop("disabled", true)
			var source = new EventSource('/contests/' + contest_id + '/status');
			source.onmessage = function(event) {
				if (event.data == checked) {
					updateBtnStatus()
					source.close()
				}
			}
		}
	})

	$("#contest-run").submit(function(e){
		e.preventDefault(); // avoid to execute the actual submit of the form.

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
			var data_form = {"metrics": send_data}
			console.log(JSON.stringify(data_form))
			$.ajax({
				type: "POST",
				url: "/api/contests/"+contest_id+"/run",
				contentType: 'application/json',
				data: JSON.stringify(data_form),
				dataType: 'json',
				success: function()
				{   
					$("#run").prop("disabled", true)
					$("#run").text("Running...")
					$("#result-btn").remove()
					var source = new EventSource('/contests/' + contest_id + '/status');
					source.onmessage = function(event) {
						console.log(event.data)
						if (event.data == checked) {
							source.close()
							$.get("/api/contests/"+contest_id+"/results", function(data){
								if (data['results'].length > 0) {
									location.reload()
								} else {
									Toast.fire({
										icon: 'error',
										title: 'No matches found!'
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

	$(document).on("click",".btn-delete",function(){
	  problem_id = $(this).attr('problem_id');
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
					url: "/api/problems/" + problem_id,
					success: function (data) {
							location.reload();
					},
					error: function (data) {
						Toast.fire({
							icon: 'error',
							title: data['error']
						})
					}
				});
			}
		})
	});
})

function createProblem() {
    const form = document.createElement('form')
    const input = document.createElement('input')
    const submit = document.createElement('input')
    const row = document.createElement('div')
    const col10 = document.createElement('div')
    const col2 = document.createElement('div')

    form.method = "POST"
    form.action = "/contests/" + contest_id + "/problems"
    form.className = "form-horizontal"

    row.className = "form-group row"
    col10.className = "col-sm-10"
    col2.className = "col-sm-2"

    input.className = "form-control"
    input.name = "problem_name"

    submit.type = 'submit'
    submit.className = 'btn btn-primary'
    submit.name = 'submit'
    submit.value = 'Submit'
    submit.id = "create-pname-btn"

    col10.appendChild(input)
    col2.appendChild(submit)

    row.appendChild(col10)
    row.appendChild(col2)

    form.appendChild(row)

    link = document.getElementById('create-problem').remove()
    
    document.getElementById('problem-name').appendChild(form)
}

