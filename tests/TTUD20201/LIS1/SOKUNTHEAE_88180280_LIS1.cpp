#include<bits/stdc++.h>
using namespace std;

#define MAX 10000
int T,n,m, res=0, f[MAX];
int a[MAX], b[MAX];


int main(){
	
	cin >> T >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	while(T--){
		int i = 1;
		f[i] = 1;
		
		for(int j = 0; j <= i; j++){
			if(f[j] + 1 > f[i] && a[j] == a[i] + 1){
				f[i] == f[j] + 1;	
			}
			if(f[i] > res){
				res = f[i];
			}
		}
		
	}
	cout << res << endl;
	return 0;
}
