#include <bits/stdc++.h>
using namespace std;
 
const int N=100+5;

main(){
	int a[N], b[N];
	set<int> s;
	int m,n, T = 1 , dem = 0;
	cin >> T >> n;
	for(int i = 1 ;i <= n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i = 1 ;i <= m; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j =1; j <= m ; j++){
			if (a[i] == b[j]){
				b[j] = -1;
				s.insert(a[i]);
				// dem ++;
				break;
			}
		}
	}
	cout << s.size();
	// cout << dem;
}

