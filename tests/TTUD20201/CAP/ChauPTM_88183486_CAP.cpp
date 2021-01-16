#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[101], b[101];

//int duyet(int a[], int b[], int n, int m){
//	int dem=0;
//	for (int i=1 ;i<= n; i++){
//		for (int j=1; j<=m; j++){
//			if (a[i]== b[j]){
//				dem++;
//			}
//		}
//	}
//}
int main(){
	cin >> t;
	while (t--){
		cin>> n;
		for (int i=1; i<=n ;i++){
			cin>> a[i];
		}
		cin >>m;
		for (int i=1; i<=m; i++){
			cin >> b[i];
		}
		for (int i=1; i<=n-1; i++){
			for (int j=i+1; j<= n;j++){
				if (a[j]==a[i] && a[j]!=-1){
					a[j]=-1;
				}
			}
		}
		for (int i=1; i<=m-1; i++){
			for (int j=i+1; j<= m;j++){
				if (b[j]==b[i] && b[j]!=-2){
					b[j]=-2;
				}
			}
		}
		int dem=0;
		for (int i=1 ;i<= n; i++){
			for (int j=1; j<=m; j++){
				if (a[i]== b[j]){
					dem++;
					break;
				}
			}
		}
		cout<< dem;
	}
}
