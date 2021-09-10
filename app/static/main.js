const init = 1
const failed = 2
const waiting = 3
const running = 4
const checked = 5
params = new URL(document.getElementById("token").src).searchParams;
var token = params.get('token')
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
            case init.toString():
                $(this).addClass("badge-secondary")
                $(this).text("init")
                break
            case waiting.toString():
                $(this).addClass("badge-info")
                $(this).text("waiting")
                break
            case running.toString():
                $(this).addClass("badge-primary")
                $(this).text("running")
                break
			case checked.toString():
				$(this).addClass("badge-success")
                $(this).text("checked")
                break
			case failed.toString():
				$(this).addClass("badge-danger")
                $(this).text("failed")
                break
		}
	})

    if (metrics.length > 0)  {
        for (metric of metrics) {
            metric_name = metric['name']
            console.log(metric_name)
            $("#"+metric_name).prop("disabled", false)
            $("#"+metric_name).val(metric['threshold']  * 100)
            $("#"+metric_name+"_check").prop("checked", true)
        }
    }

    $('#reset').click(function resetStatus() {
        type = $(this).attr('dtype')
        // console.log(type)
        if (type == 'contest') {
            // console.log(contest_id)
            url = '/api/contests/'+ contest_id + '/reset'
        } else if (type == 'problem') {
            console.log(problem_id)
            url = '/api/problems/'+ problem_id + '/reset'
        }
        $.ajax({
            type: "PUT",
            contentType: 'application/json',
            url: url,
            headers: {
                Authorization: 'Bearer '+token
            },
            success: function (data) {
                console.log(data['info'])
                location.reload();
            },
            error: function (data) {
                Toast.fire({
                    icon: 'error',
                    title: data.responseText
                })
            }
        });
    });
})

document.getElementById('count_operator_check').onchange = function() {
    document.getElementById('count_operator').disabled = !this.checked;
};

document.getElementById('set_operator_check').onchange = function() {
    document.getElementById('set_operator').disabled = !this.checked;
};

document.getElementById('hash_operator_check').onchange = function() {
    document.getElementById('hash_operator').disabled = !this.checked;
};

document.getElementById('moss_score_check').onchange = function() {
    document.getElementById('moss_score').disabled = !this.checked;
};