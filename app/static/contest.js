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
        timer: 3000
    });
    
    $(document).on("click",".btn-delete",function(){
        contest_id = $(this).attr('contest_id');
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
                headers: {
                    Authorization: 'Bearer '+token
                },
                url: "/api/contests/" + contest_id,
                success: function (data) {
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
})