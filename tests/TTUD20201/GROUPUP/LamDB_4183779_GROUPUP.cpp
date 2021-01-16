#include<bits/stdc++.h>
using namespace std;
int a[10000];
int s=0;
int Hopnhat(int n){
	int max =0;
	if (n==1) return s;
	else{
	if (n%2==1) {
		for (int i=0; i<n/2;i++){
			a[i]=a[i*2]+a[i*2+1];
			if(a[i]>max) max=a[i];
		}
		a[n/2]=a[n-1];
        s=s+max;
        return Hopnhat(n/2+1);
	}
	else {
		for (int i=0;i<n/2;i++){
			a[i]=a[i*2]+a[i*2+1];
			if(a[i]>max) max=a[i];}
			s=s+max;
			return Hopnhat(n/2);
		
	}
}
}
int main() {
	int T; cin>>T;
	for (int k=0; k< T;k++){
		int n;cin>>n;
		for(int j=0;j<n;j++) cin>>a[j];	
		cout<<Hopnhat(n);
	}
	return 0;
}
