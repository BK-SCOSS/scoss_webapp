#include<bits/stdc++.h>
using namespace std;
int a[500],b[500];
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>b[i];
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]) continue;
			int y=0;
			for(int j=1;j<m;j++){
				if(b[j]==a[i]) y++;
			}
			if(y>0) res++;
		}
		cout<<res<<endl;
	}
}
