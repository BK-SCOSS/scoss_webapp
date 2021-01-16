#include<bits/stdc++.h>

using namespace std;
int main(){
	int t;
	cin >> t;
	
	int i,j,k;
	int n,m;
	for( i=0;i<t;i++){
		int dem = 0;
		cin >> n ;
		int a[n];
			for( j=0;j<n;j++){
				cin >> a[j];
			}
		cin >> m;
		int b[m];
			for( k=0;k<m;k++){
				cin >> b[k];
			}
			for(j=0;j<n;j++){
				for(k=0;k<m;k++){
				 if(a[j]==b[k]){
				 	dem = dem +1;
				 	break;
				 }	
				}
			}
			cout << dem;
	}
	
}
