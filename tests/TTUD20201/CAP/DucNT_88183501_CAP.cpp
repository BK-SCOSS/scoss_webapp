#include<bits/stdc++.h>
using namespace std;
int t,n,m,res;
int a[100];
int b[100];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=0;i<t;i++){
		memset(a,0 , sizeof(a));
		memset(b,0, sizeof(b));
		res=0;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>b[j];
		}
		sort(a,a+n);
		for(int j=0;j<n;j++){
			if(a[j]==a[j+1]){
				a[j]=1000000000;
			}
		}
		sort(a,a+n);
		sort(b,b+m);
		for(int j=0;j<m;j++){
			if(b[j]==b[j+1]){
				b[j]=1000000000;
			}
		}
		sort(b,b+m);
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(a[j]==b[k]){
					res++;
					break;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
		
