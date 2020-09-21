# A Source Code Similarity System - SCOSS


## TODO
* Output
	* Framework, python package mà người khác có thể sử dụng trong code của họ đc. ( giống sctokenizer )
	* Webapp, front-end đơn giản, và có thể deploy và test được.
		* Functions: Up file .zip lên và check trùng trong file zip
		* Cung cấp API để ct khác có thể tương tác được. POST, GET
	* Command-line 

* 3 similarities. --> tương lai cần các độ do mới. vd xây dựng cây (papers)
* Yêu cầu thiết kế: 
	* Thêm độ đo là dễ dàng.
	* Có 1 cái ngưỡng. x, y, z: (80, 90, 95)  
	* Hỗ trợ stateness. (đưa x file .cpp vào) + đưa thêm 1 file .cpp. Thiết kế transaction.
		* Kịch bản: Trước đó người dùng A đưa x file .cpp -> 12315
		* POST add_file/12315
		* GET results/12315
