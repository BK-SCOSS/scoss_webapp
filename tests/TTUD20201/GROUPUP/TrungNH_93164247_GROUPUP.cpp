#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
int main(){
	int T,kq;
	cin>>T;
	while(T--){
		kq=0;
		cin>>n;
		for(int i=1;i<=n;i++){
				cin>>a[i];
			}
		while(n>1){
		if(n%2==0){
			int t=0;
			for(int i=1;i<=n/2;i++){
				a[i] = a[i*2-1]+a[i*2];
				t = max(t,a[i]);
			}
			kq=kq+t;
			n=n/2;
		}
		else{
			int t=0;
			for(int i=1;i<=n/2;i++){
				a[i] = a[i*2-1]+a[i*2];
				t = max(t,a[i]);
			}
				a[n/2+1]=a[n];
				kq=kq+t;
				n=n/2+1;
			}
		}
		cout<<kq<<endl;		
	}
	
}
