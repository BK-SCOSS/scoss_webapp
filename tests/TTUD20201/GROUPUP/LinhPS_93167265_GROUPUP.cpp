#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
	        int a ;
			int cnt = 0; 
	        cin >> a;
	        int arr[a];
	        queue<int> q1;
	        for(int i = 0 ; i < a ; i++){
	        	cin >> arr[i];
	        	q1.push(arr[i]);
			}
			while(q1.size() > 1){
				int dai = q1.size();
	
				int max1 =0;
				for(int i = 0; i < dai -1 ; i = i + 2 ){

					int t1 = q1.front();
					q1.pop();
					int t2 = q1.front();
					q1.pop();
					q1.push(t1+t2);
					max1 = max(max1,t1+t2); 
				}
				cnt += max1;
				if(dai %2 != 0){
					int t3 = q1.front();
					q1.pop();
					q1.push(t3);
				}	
			}
			cout << cnt << endl;
	}
	return 0;
}
