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

function getStatusLabel(statusValue) {
    var badge, status_label;
    switch(statusValue){
        case init:
            badge = "badge-secondary"
            status_label = "init"
            break
        case waiting:
            badge = "badge-info"
            status_label = "waiting"
            break
        case running:
            badge = "badge-primary"
            status_label = "running"
            break
        case checked:
            badge = "badge-success"
            status_label = "checked"
            break
        case failed:
            badge = "badge-danger"
            status_label = "failed"
            break
    }
    return `<span class="status badge ${badge}">${status_label}</span>`
}