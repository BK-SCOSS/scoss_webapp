#include<bits/stdc++.h>

using namespace std;
int main(){
	int t,i,j,k;
	cin >> t;
	for(i=0;i<t;i++){
		int n;
		cin >> n;
		int a[n];
		int max=0;
		int dem=0;
		
		for(j=0;j<n;j++){
			cin >> a[j];
			
		}
		int tam;
		for(j=0;j<n;j++){
			int dem=1;
			tam = a[j];
			for(k=j+1;k<n;k++){
				if(a[k]-tam ==1){
					tam = a[k];
					dem = dem +1;
				}		
			}
			if ( dem > max){
				max = dem;
			}
		}
		cout << max;
		
	}
}
