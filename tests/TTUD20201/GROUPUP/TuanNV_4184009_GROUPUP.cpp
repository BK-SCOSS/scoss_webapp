#include<bits/stdc++.h>

using namespace std;
int main(){
	int t,i,j,k;
	cin >> t;
	int tong =0;
	for (i=0;i<t;i++){
		int n;
		cin >> n;
		int max;
		int a[n];
		for(j=0;j<n;j++){
			cin >> a[j];
		}
		if (n==1) return a[0];
		for(k=0;pow(2,k)<n;k++){
		
			for(j=0;j<n/2;j++){
				a[j]=a[2*j]+a[2*j+1];
				if ((2*j+1)>=n)break;
			}
			for(j=n/2;j<n;j++){
				a[j]=0;}
				max =a[0];
			for(j=0;j<n;j++){
				if( max < a[j]){
					max = a[j];
				}
			}
			tong= tong + max;
		}
		cout << tong;		
	}
}
