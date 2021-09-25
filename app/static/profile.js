$(document).ready(function() {
    const Toast = Swal.mixin({
		toast: true,
		position: 'top-end',
		showConfirmButton: false,
		timer: 5000
	})

	$.ajax({
		type: "GET",
		contentType: 'application/json',
		url: "/api/users/"+ user_id + "/token",
		headers: {
			Authorization: 'Bearer '+token
		},
		success: function (data) {
			public_token = data['public_token']
            if (public_token == 'delete'){
                public_token = ""
            }
            var text_key = document.getElementById("display_key")
            text_key.innerHTML = public_token
			// location.reload();
		},
		error: function (data) {
			console.log(data.responseText)
		}
	});
    $(document).on("click", "#del_key", function () {
        if (confirm("Bạn chắc chắn muốn xóa chứ?")) {
            $.ajax({
                type: "DELETE",
                contentType: 'application/json',
                headers: {
                    Authorization: 'Bearer '+ token
                },
                url: "/api/users/"+user_id+"/delete_token",
                success: function (data) {
                    console.log('success')
                    location.reload()
                },
                error: function (data) {
                    console.log('Error:', data['error']);
                }
            });
        }
    });
    $(document).on("click", "#gen_key", function () {
        $.ajax({
            type: "GET",
            contentType: 'application/json',
            headers: {
                Authorization: 'Bearer '+ token
            },
            url: "/api/users/"+user_id+"/create_token",
            success: function (data) {
                console.log('success')
                location.reload()
            },
            error: function (data) {
                console.log('Error:', data['error']);
            }
        });
    
    });
})