#include <iostream>
#include <bits/stdc++.h>

const int lim = 1e3;

int n, m;
int a[lim] = {}, b[lim] = {};

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
}

void solve() {
	int i = 0, j = 0;
	int cnt = 0;
	std::sort(a, a+n);
	std::sort(b, b+m);
	while (i < n && j < m) {
		if (a[i] == b[j]) {
			cnt++;
			i++;
			j++;
		} else if (a[i] < b[j]) {
			i++;
		} else {
			j++;
		}
	}
	std::cout << cnt << "\n";
}

int main(int argc, char** argv) {
	int t = 0;
	std::cin >> t;
	while (t--) {
		input();
		solve();
	}
	return 0;
}
