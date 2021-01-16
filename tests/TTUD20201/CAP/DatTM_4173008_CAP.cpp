#include<bits/stdc++.h>
using namespace std;

int T,m,n,z;
long a[105],b[105],c[105],ans;

int main(){
	cin >> T;
	for(int k=1;k<=T;k++){
		cin >> n ;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}

		cin >> m ;
		for(int i=1;i<=m;i++){
			cin >> b[i];
		}
		z=0;
		for(int i=1;i<=n;i++){
			if(i>1) for(int j=0;j<z;j++)
				if(a[i]==c[j]) continue;
			for(int j=1;j<=m;j++){
				if(a[i]==b[j]) {
					ans++;
					c[z]=a[i];z++;
					break;
				}
			}
		}

	}
	cout << ans << endl;
  return 0;
}
