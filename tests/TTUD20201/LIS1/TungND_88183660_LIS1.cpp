#include<iostream>
#include<algorithm>
using namespace std;

void inputData();
int lis1(int i);
int check(int size);

int T, n;
int a[1000010];
int mem[1000010];

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		inputData();
		for (int i = 0; i < n; i++)mem[i] = -1;
		for (int i = 0; i < n; i++)mem[i] = lis1(i);
		cout << check(n) << endl;
	}
	return 0;
}

void inputData() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int lis1(int i) {
	if (mem[i] != -1) {
		return mem[i];
	}

	int res = 1;
	for (int j = 0; j < i; j++) {
		if (a[j] == (a[i] - 1)) {
			res = max(res, 1 + lis1(j));
		}
	}

	mem[i] = res;
	return res;
}

int check(int size) {
	int mx = 0;
	for (int i = 0; i < size; i++) {
		mx = max(mx, mem[i]);
	}
	return mx;
}