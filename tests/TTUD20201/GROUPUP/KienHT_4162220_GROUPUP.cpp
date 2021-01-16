#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >>T;
	for(int i =0 ; i< T; i++){
		int n;
		cin >> n;
		int A[n];
		for(int j =0; j< n; j++){
			cin >>A[j];
		}
		vector<int> vec;
		vector<int> vec_tmp;
		
		//thuat toan:
		int times=0;
		int so_lan_hop;
		if(n ==1){
		so_lan_hop = 0;
		times = A[0];
		}else {
			
			for(int t =0; t < n; t++){
				vec.push_back(A[t]);
			}
			
			while(vec.size()>1){
				int tmp =vec.size();
				vec.clear();
				for(int k =0; k<tmp ; k=k+2){
					vec.push_back(vec_tmp[k]+vec_tmp[k+1]);
				}
				
				vec_tmp.clear();
				for(int b =0; b< vec.size(); b++){
					vec_tmp.push_back(vec[b]);
				}
				
				int max = vec[0];
				for(int m =1; m < vec.size(); m++){
					if(vec[m]>max){
						max = vec[m];
					}
				}
				times = times + max;
			}
		}
		cout <<vec.size();
		cout <<vec[0];
		
		
		
		cout <<times;
	}
}
