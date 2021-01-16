#include<iostream>

int T, n, m, a[101], b;
int i,j;

using namespace std;

int main(){
	cin >> T;
	for (int p = 0; p < T; p++) {
		int res = 0;
		cin >> n;
		for (i = 0; i < n; i++) cin >> a[i];
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> b;
			for (j = 0; j < n; j++)
				if (a[j] == b) {
					res++; break;
				}
		}
		cout << res << endl;		
	}
}