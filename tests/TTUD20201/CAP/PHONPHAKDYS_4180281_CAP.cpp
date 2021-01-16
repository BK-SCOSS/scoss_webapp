#include <iostream>
#include <algorithm>
using namespace std;
int a[100],b[100];
int c[10010];
int cn;
int main(){
	int t,n,m,cn;
	cin>>t;
	for (int q=1;q<=t;q++){
		cn=0;
		cin>>n;
		for (int i=0;i<=n-1;i++) cin>>a[i];
		cin>>m;
		for (int i=0;i<=m-1;i++) cin>>b[i];
		for (int i=0;i<=n-1;i++)
		for (int j=0;j<=m-1;j++) if (a[i]==b[j]) {
			cn++;
			c[cn]=a[i];
		}
		if (cn>=0) sort(c,c+cn);
		int r=cn;
		for (int i=1;i<=cn-1;i++) if (c[i]==c[i+1]) r--;
		cout<<r<<endl;
	}
}