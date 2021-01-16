#include<iostream>
#include<algorithm>
#include<stack>
#include<deque>
const int N = 100005;
const int T = 11;
using namespace std;


int n,rs[T];
int length;
int a[T][N];

void cal (int i){
	stack<int> st;
	deque<int> dq;
	int maxx = 0;
	int r = 0;

	for(int j = length-1; j >= 0; j--){
		st.push(a[i][j]);
	}
	
	while(st.size() > 1){
		int p,q;
    	p = st.top();
    	st.pop();
    	q = st.top();
	    st.pop();
		
    	maxx = max(maxx,p+q);
    	dq.push_back(p+q);
    	
    	if(st.size() <= 1){
    		
    		r += maxx;
    		maxx = 0;
    		
    		while(dq.size() > 0){
    			st.push(dq.back());
    	    	dq.pop_back();
			}	
		}
		
		
	}
	rs[i] = r;
}

int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> length;
		for(int j = 0; j < length; j++){
			cin >> a[i][j];
		}
		
		cal(i);
	}
	
	for(int i = 0; i < n; i++){
		cout << rs[i] << endl;
	}
	
	return 0;
}
