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

	$(".status").each(function(){
		switch($(this).text()){
			case "checked":
				$(this).addClass("badge-success")
				break
			case "init":
				$(this).addClass("badge-secondary")
				break
			case "running":
				$(this).addClass("badge-primary")
				break
			case "failed":
				$(this).addClass("badge-danger")
				break
			case "waiting":
				$(this).addClass("badge-info")
				break
		}
    })

	$.get("/api/contests/"+ contest_id + "/status", function(data){
		if (data['contest_status'] == "checked") {
			result = $("<button>", {"class": "btn btn-default", "id":"result"})
			a = $("<a>", {"href":"/contests/"+contest_id+"/results", "target": "_blank"})
			a.text("Result")
			result.append(a)
			$(".card-footer").append(result)
			$("#run").text("Rerun")
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
			var data_form = {'metrics': send_data}
			$.ajax({
				type: "POST",
				url: "/api/contests/"+contest_id+"/run",
				contentType: 'application/json',
				data: JSON.stringify(data_form),
				success: function()
				{   
					$("#run").disabled
					$("#run").append("<span>", {"class": "pinner-border spinner-border-sm"})
					$("#run").text("Running...")
					$(".card-footer #result").remove()
					var source = new EventSource('/contests/' + contest_id + '/status');
					source.onmessage = function(event) {
                        console.log(event.data)
                        if (event.data == 'checked') {
							$.get("/api/contests/"+contest_id+"/results", function(data, status){
								var result = JSON.stringify(data)
								if (data['results'].length > 0) {
									result = $("<button>", {"class": "btn btn-default", "id":"result"})
									a = $("<a>", {"href":"/contests/"+contest_id+"/results", "target": "_blank"})
									a.text("Result")
									result.append(a)
									$(".card-footer").append(result)
									$("#run").empty()
									$("#run").text("Rerun")
									$("#run").removeAttr("disabled")
									source.close()
								} else {
									Toast.fire({
										icon: 'error',
										title: 'No result in database'
									})
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