#include <bits/stdc++.h>
using namespace std;

int n, m, *a, *b, result;

void solve(){
	set<int> temp;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] == b[j]){
				temp.insert(a[i]);
				break;
			} 
		}
	}
	result = temp.size();
}

int main(){
	int t;
	cin >> t;
	while(t>0){
		result = 0;
		cin >> n;
		a = new int[n+1];
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		cin >> m;
		b = new int[m+1];
		for(int j = 1; j <= m; j++){
			scanf("%d", &b[j]);
		}
		solve();
		cout << result << endl;
		t--;
	}
}
