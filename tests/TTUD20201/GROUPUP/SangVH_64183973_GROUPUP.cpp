#include<bits/stdc++.h>
using namespace std;
int n;
int a[100006],b[100005];
int main(){
	int T;
	cin>>T;
	while(T--){
	cin>>n;
	int res=0;
	for(int i=1;i<n+1;i++){
		cin>>a[i];
	}
	while(n>1){
		int m=0,k=0;
		for(int i=1;i<n;i+=2){
			if(m<a[i]+a[i+1]) m=a[i]+a[i+1];
			b[++k]=a[i]+a[i+1];
		}
		if(n%2==1) b[++k]=a[n];
		for(int i=1;i<=k;++i) a[i]=b[i];
		n=k;
		res+=m;
	}
	cout<<res<<endl;
		
	}
}
