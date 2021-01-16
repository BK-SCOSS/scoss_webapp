#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int kt(int *a, int id){
	int res=1;
	if(id==0) return 1;
	else{
		for(int i=0;i<id;i++){
			if(a[i]==a[id]){
				res=0; 
				break;
			}
		}
	}
	return res;
}
int main(){
	int dem;
	int t;
	cin>>t;
	int n,m;
	for(int i=1;i<=t;i++){
		dem = 0;
	cin>>n; int a[n];
	for(int i=0;i<n;i++) { cin>>a[i];
}
cin>>m; int b[m];
	for(int i=0;i<m;i++) { cin>>b[i];
}
for( int j=0;j<n;j++){
	if (kt(a,j)) {
		for(int k=0;k<m;k++){ 
			if(a[j]==b[k]&&kt(b,k)){
				dem+=1;
				break;
			}
		}
		
	}
} 
cout<< dem <<endl;
}
}