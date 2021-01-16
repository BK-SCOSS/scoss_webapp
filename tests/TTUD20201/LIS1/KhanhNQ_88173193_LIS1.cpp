#include <bits/stdc++.h>

using namespace std;
int main () {
int t,out;
	cin>>t;
	int c[t];
	for (int i=0;i<t;i++) {
		int n;
		cin>>n;
		int a[n];
		for (int k=0;k<n;k++) cin>>a[k];
		out=0;
		for (int k=0;k<n;k++) {
			int flag=a[k];
			int dem=1;
			for (int j=k+1;j<n;j++) if (a[j]==(flag+1)) {dem++;flag=a[j];}
			if (dem>=out) out=dem;
		}
		c[i]=out;
	}
	for (int i=0;i<t-1;i++) cout<<c[i]<<endl;
cout<<c[t-1];
return 0;
}
