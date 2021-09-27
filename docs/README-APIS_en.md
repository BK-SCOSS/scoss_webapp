## API

### 1. Token to use API
For generating a token, navigate to **Update profile** > **Generate**.

To revoke the token, use the **Delete** button.

![create token](https://github.com/BK-SCOSS/scoss_webapp/blob/master/docs/create_token.png)

### 2. Public API Usage
#### 1. API to create a project: `/api/project` with POST method
**Request**

Query Parameters

* public_token (string): token for API authentication.

Body (from-data)

* project_name (string): project's name
* file: the zip file containing sources for similarity checking.
File zip có format như sau:

```sh
    Problem A/
    ├── a.cpp
    ├── b.py
    ├── c.java
    ├── ...

``` 
and one or more of the following metrics:
* count_operator (float): the threshold for the count operator, which is in the range (0,1).
* set_operator (float): the threshold for the set operator, which is in the range (0,1).
* hash_operator (float): the threshold for the hash operator, which is in the range (0,1).
* moss_score (float): the threshold for moss score, which is in the range (0,1).


**Response**

Body

* project_id (string): The generated project's id.
* url_result (string): URL to the similarity checking result.

#### 2 . API to get the result `/api/project/<project_id>/results` with GET method  

**Response**

* project_id: project's id.
* project_name: project's name.
* project_status: project's status.
* results: URL to the similarity checking result.

#### 3. API to get information about all project `/api/project` with GET method 
**Request**

Query Parameters

* public_token (string): token for API authentication.

**Response**

Each created project includes the following information:

* project_id (string): project's id.
* project_status (string): project's status (`init`, `waiting`, `running`, `checked`, `failed`).
* project_name (string): project's name.
* sources (string): source code list.
* metrics (list): metric list.

#### 4. API to get a project details `/api/project/<project_id>` with GET method  
**Response**

Project details:

* project_id (string): project's id.
* project_status (string): project's status (`init`, `waiting`, `running`, `checked`, `failed`).
* project_name (string): project's name.
* sources (string): source code list.
* metrics (list): metric list.

#### 5. API to delete a project `/api/project/<project_id>` with DELETE method   
**Request**

Query Parameters

* public_token (string): token for API authentication.

**Response**

* success: True
