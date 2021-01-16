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
		for (int i=0;i<n;i++) cin>>a[i];
		out=0;
		while (n>1) {
			if (n%2==0) {
				for (int k=0;k<n/2;k++) a[k]=a[2*k]+a[2*k+1];
				int max=a[0];
				for (int k=0;k<n/2;k++) if (a[k]>=max) max=a[k];
				n/=2;
				//cout<<"maxchan ="<<max<<endl;
				out+=max;
				//cout<<"outchan ="<<out<<endl;
			} else {
				int j;
				for (j=0;j<n/2;) {a[j]=a[2*j]+a[2*j+1];j++;}
				a[j]=a[n-1];
				int max=a[0];
				//for (int j=0;j<n/2+1;j++) cout<<"a["<<j<<"] = "<<a[j]<<endl;
				for (int j=0;j<n/2;j++) if (a[j]>=max) max=a[j];
				n=n/2+1;
				//cout<<"maxle ="<<max<<endl;
				out+=max;
				//cout<<"outle ="<<out<<endl;
			}
		}
			c[i]=out;
	}
	for (int i=0;i<t-1;i++) cout<<c[i]<<endl;
cout<<c[t-1];
return 0;
}
