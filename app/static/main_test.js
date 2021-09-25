const init = 1
const failed = 2
const waiting = 3
const running = 4
const checked = 5
const id_test = "test_scoss"
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
        url = '/api/project/'+ id_test + '/reset'
        $.ajax({
            type: "PUT",
            contentType: 'application/json',
            url: url,
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