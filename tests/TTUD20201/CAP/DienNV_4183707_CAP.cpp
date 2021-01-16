#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
       	int n;
		cin >> n;
		map<long long, int> mark1;
		long long a[n];
	    vector<long long> a1;
		for(int i =0 ; i< n; i++){
	            cin >> a[i];
	            mark1[a[i]] = 0;
	        } 
		for(int i =0; i <n; i++ ){
	        	if(mark1[a[i]] == 0){
	        		mark1[a[i]] =1;
	        		a1.push_back(a[i]);
				}
			} 
		int m;
		cin >> m;
		map<long long, int> mark2;
		long long b[m];
	    vector<long long> b1;
		for(int i =0 ; i< m; i++){
	            cin >> b[i];
	            mark2[b[i]] = 0;
	        } 
		for(int i =0; i <m; i++ ){
	        	if(mark2[b[i]] == 0){
	        		mark2[b[i]] =1;
	        		b1.push_back(b[i]);
				}
			} 
		
       	
		
        int cnt =0;
        for(int i =0 ; i < a1.size(); i++){
            for(int j =0; j< b1.size(); j++){
                if(a1[i] == b1[j]){
                    cnt ++;
                    break;
                }
            }
        }
        cout << cnt;
        
    }

    

    return 0;
}
