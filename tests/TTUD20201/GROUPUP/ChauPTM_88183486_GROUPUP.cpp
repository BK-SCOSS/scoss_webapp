#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100001];
int main(){
	cin >>t;
	while (t--){
		cin>> n;
		for (int i=1; i<= n; i++){
			cin>> a[i];
		}
		int m=0;
		while (n>1){
			int M=0;
			for (int i=1; i<n; i=i+2){
				a[i/2+1]= a[i]+a[i+1];
				M= max(M, a[i/2+1]);
			}
//			for( int i=1; i<=n; i++){
//				cout <<a[i];
//			}
			m= m+ M;
			if (n%2==0){
				n=n/2;
			} else {
				a[n/2+1]= a[n];
				n=n/2+1;
			}
		}
		cout<< m;
	}	

}
