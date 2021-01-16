#include <bits/stdc++.h>

using namespace std;
int main() {
	int t,out;
	cin>>t;
	int c[t];
	for (int i=0;i<t;i++) {
	int n,m;
	cin>>n;
	int a[n];
	for (int j=0;j<n;j++) {
	cin>>a[j];
	for (int l=0;l<j;l++)
	if (a[j]==a[l]) a[j]=-2507;
}
	cin>>m;
	int b[m];
	for (int k=0;k<m;k++) cin>>b[k];
	out=0;
	for (int j=0;j<n;j++)
	for (int k=0;k<m;k++) if (a[j]==b[k]) out++;
	c[i]=out;
}
for (int i=0;i<t-1;i++) cout<<c[i]<<endl;
cout<<c[t-1];
return 0;
}
