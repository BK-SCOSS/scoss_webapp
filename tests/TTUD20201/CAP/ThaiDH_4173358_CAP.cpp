#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int T, n, m;
int ans = 0;
unsigned long long a[N], b[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	if (T > 10) return 0;
	for (int i = 1; i <= T; i++){
		cin >> n;
		for (int j = 1; j <= n; j++){
			cin >> a[j];
		}
		
		cin >> m;
		for (int k = 1; k <= m; k++){
			cin >> b[k];
		}
		
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= m; k++){
				if (a[j] != b[k]) continue;
				else ans += 1;
			}
		}
		cout << ans;
	}
}
