#include<bits/stdc++.h>
using namespace std;

int T,n,m, res=0;
int a[1000], b[1000];

int main(){
	
	
	cin >> T;
		
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		cin >> m;
		for(int i = 1; i <= m; i++){
			cin >> b[i];
		}
		
		for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] == b[j]){
				res++;
			}
		}
	}
		
	}

	cout << res;

	return 0;
}
