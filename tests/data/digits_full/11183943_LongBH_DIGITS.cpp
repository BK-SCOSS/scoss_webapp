#include<iostream>
using namespace std;

int T, n, ans = 0;
int c[7]; // H, U, S, T, O, I, C in order
int marked[10];

bool check(int k, int i) {
	if (k == 0 || k == 2) {
		if (i == 0) return false;
	}
	if (marked[i] == 0) return true;
	else return false;
}

void solution() {
	int S = c[0]*1000 + c[1]*100 + c[2]*10010 + c[3]*2 + c[4]*1000 + c[5]*100 + c[6]*10;
	if (S == n) {
		ans++;
	}
}

void tryD(int k) {
	for (int i = 0; i <= 9; i++) {
		if (check(k, i)) {
			c[k] = i;
			marked[i] = 1;
			if (k == 6) {
				solution();
			} else tryD(k+1);
			marked[i] = 0;
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i <= 9; i++) marked[i] = 0;
	while (T--) {
		cin >> n;
		tryD(0);
		cout << ans << endl;
		ans = 0;
	}
}
