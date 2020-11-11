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

    $(".status").each(function(){
        if ($(this).text() == "checked") {
            $(this).addClass("badge-success")
        }
        else if ($(this).text() == "init") {
            $(this).addClass("badge-secondary")
        }
        else if ($(this).text() == "running") {
            $(this).addClass("badge-primary")
        }
        else if ($(this).text() == "failed") {
            $(this).addClass("badge-danger")
        }
        else if ($(this).text() == "waiting") {
            $(this).addClass("badge-info")
        }
    })

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
                url: "/api/contests/" + contest_id,
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