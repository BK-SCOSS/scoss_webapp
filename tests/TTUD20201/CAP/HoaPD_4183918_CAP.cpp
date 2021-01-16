#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
vector<int> a,b;
int res;
int main() {
	cin >> t;
	for(int i = 0; i< t; i++){
		map<int , int > check;
		res = 0;
		cin >> n;
		a.resize(n+1);
		for(int j = 1; j<=n; j++ ){
			cin >> a[j];
			
		}
		
		cin >> m;
		b.resize(m+1);
		for(int j = 1; j <=m; j++){
			cin >> b[j];
		}
		
		for(int j = 1; j<=n; j++){
			for(int k = 1; k<=m; k++){
				if(a[j] == b[k] && check[a[j]] == 0){
					res++;
					check[a[j]] = 1;
				}
			}
		}
		cout << res << endl;
	}
	
}
