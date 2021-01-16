#include<bits/stdc++.h>

using namespace std;
int TRY(int a[],int n){
	if(n==1) return 0;
	int res=0;
	int count=0;
	int b[n];
	for(int i=0;i<n;i+=2){
		if(i==n-1){
			b[count]=a[i];
			count++;
			res=max(res,a[i]);
		}
		else{
			b[count]=a[i]+a[i+1];
			count++;
			res=max(res,a[i]+a[i+1]);
		}
	}
	return res+TRY(b,count);
}
int main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<TRY(a,n);
	}
}
