#include<bits/stdc++.h>
using namespace std;
main(){
	int n, T;
	cin>>T;
	for(int u = 0; u<T; u++){
		cin>>n;
		vector<int> a(n), lis(n,1);
		for(int i = 0; i< n;i++){
			cin>>a[i];
		}	
		int r=0;
		for(int i = 1; i< n;i++){
			for(int j = 0; j<i;j++){
				if(a[j]==a[i]-1){
					lis[i] = max(lis[i],lis[j]+1);
				}
				r=max(lis[i],r);
			}
		}
		cout<<r<<endl;
	}
}
