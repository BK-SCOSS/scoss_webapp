# How to create contest
We have two ways to create a contest:

## Using zip file to create a
1. In contest list page, click on create button to create a new contest.
<img src="/static/images/create_contest.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">

2. Then click on contest, click choose file to add a zip file.
<img src="/static/images/add_zip.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">
3. File zip must have a defined folder structure as below:

```sh
    Contest_name/
        ├── Problem A/
        │   ├── a.cpp
        │   ├── b.py
        │   ├── ...
        │   └── c.java
        ├── Problem B/
        │   ├── d.py
        │   ├── e.py
        │   └── f.c
        └── ...
```
4. After submitting successfully, we have result as below:
<img src="/static/images/result_add_zip.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">

## Create manually
1. In contest list page, click on create button to create a new contest.

2. Then click on contest, click on "Add new problem".
<img src="/static/images/create_problem.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">

3. Type problem name and submit.
<img src="/static/images/type_pname.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">

4. When problem is created, click on it.
<img src="/static/images/list_problem.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">
5. Click on "Add new source"

6. Type mask and choose file (if mask is empty, it will be file name)
<img src="/static/images/add_source.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">

7. Result
<img src="/static/images/result_s.png" style="display: block;margin-left: auto;
margin-right: auto;width: 70%;">

# How to run
We can run a contest a a problem
To run a contest, we go to contest page. Then, we can choose metric's threshold and click run to run contest.