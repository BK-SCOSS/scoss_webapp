#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int t;
	cin>>t;
	while(t--){
		int m,n;
		int cnt=0;
		long long v[1000000002]={0};
		int a[102],b[102];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]==b[j]&&v[a[i]]==0){
					cnt++;
					v[a[i]]==1;
				}
			}
		}
		cout<<cnt;
	}

	return 0;
}

