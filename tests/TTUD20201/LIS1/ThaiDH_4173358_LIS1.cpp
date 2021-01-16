#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int T, n;
int cnt = 1;
int a[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> n;
		for (int j = 1; j <= n; ++j){
			cin >> a[j];
			if (a[j - 1] >= a[j]) continue;
			else{
				if (a[j] > a[j - 1] + 1) continue;
				else cnt += 1;
			}
		}
		cout << cnt;
	}
}
