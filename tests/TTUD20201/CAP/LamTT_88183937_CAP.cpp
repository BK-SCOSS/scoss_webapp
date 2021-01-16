#include<bits/stdc++.h>
 
using namespace std;

int k,n,m;
int a[105];
int b[105];
int c[105];

void NhapMang() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}	
	
	cin >> m;
	for (int j = 1; j <= m; j ++) {
		cin >> b[j];
	}
}

void BaiGiai() {
	int q = 0;
	for (int i = 1; i <= k; i++) {
		NhapMang();
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++){
				if (a[i] == b[j]) {
					q += 1;
					break;
				} else continue;
			}
		}
		c[i] = q;
		q = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> k;
	
	if (k == 0) cout << 0;
	
	BaiGiai();
	
	for (int i = 1; i <= k; i++) {
		cout << c[i] << endl;
	}
	
	
}
