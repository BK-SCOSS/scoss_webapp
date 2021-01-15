const init = 1
const waiting = 2
const running = 3
const checked = 4
const failed = 5

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