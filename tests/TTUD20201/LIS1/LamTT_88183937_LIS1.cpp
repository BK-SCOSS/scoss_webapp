#include<bits/stdc++.h>

#define MAX 100005
 
using namespace std;

int t, n;
int a[MAX];
int b[MAX];

void NhapMang() {
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void test() {
	for (int i = 1; i <= t; i++) {
		NhapMang();

		int k = 1;
		int p = 1;
		for (int i = 1; i <= n; i ++) {
			int q = a[i];
			int j = i + 1;
			while ( j <= n) {
				if (q == (a[j] - 1)) {
					k += 1;
					q = a[j];
					i = j;
				} else ++j ;
			}
			p = max(k, p);
			k = 0;
		}
		b[i] = p ;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> t >> n;
	
	if (t == 0) cout << 0;
	
	test();
	
	for (int i = 1; i <= t; i++) {
		cout << b[i] << endl;
	}
}
