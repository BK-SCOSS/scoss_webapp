#include <iostream>
#include <map>
using namespace std;

int a[105], b[105];
int c[105] = {};
int n, m;
int T;
int main() {
	cin >> T;
	int i, j;
	for (int dsa = 0; dsa < T; dsa++) {
		cin >> n;
		int res = 0;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> m;
		for (i = 0; i < m; i++){
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] == b[j] && !c[i]) {
					res++;
					c[i] = 1;
				}
			}
		}
		cout << res << endl;
	}
}