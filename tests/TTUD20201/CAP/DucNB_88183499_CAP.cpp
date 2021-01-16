#include<bits/stdc++.h>

using namespace std;

int main(){
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cin>>m;
		int b[m];
		for(int i=0;i<m;i++){
			cin>>b[i];
		}
		sort(a,a+n);	
		sort(b,b+m);	
		int count=0;
		for(int i=0;i<n;i++){
			if(i>=1){
				if(a[i]==a[i-1]) continue;
			}
			for(int j=0;j<m;j++){
				if(a[i]==b[j]){
					count++;
					break;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
