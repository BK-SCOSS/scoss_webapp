#include <iostream>

using namespace std;

int X[7]; // H U S T O I C
int appeared[10];
int ans, N;

void solution() {
	int T = X[0]*1000 + X[1]*100 + X[2]*10 + X[3] + X[2]*10000 + X[4]*1000 + X[5]*100 + X[6]*10 + X[3];
	if (T == N) {
		ans++;
	}
}

void init() {
	for (int i = 0; i < 10; i++) {
		appeared[i] = 0;
	}
}

void TRY (int k) {
	for (int i = 0; i < 10; i++) {
		if (appeared[i] == 0) {
			X[k] = i;
			appeared[i] = 1;
			if (k == 6) {
				if (X[0] != 0 && X[2] != 0) {
					solution();
				}
			} else {
				TRY(k + 1);
			}
			appeared[i] = 0;
			}
	}
}

int main() {
	int n;
	cin >> n;
	int result[51];
	for (int i = 0; i < n; i++) {
		cin >> N;
		init();
		ans = 0;
		TRY(0);
		result[i] = ans;
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}
	
	return 0;
}
