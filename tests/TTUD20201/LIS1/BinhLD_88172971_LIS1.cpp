#include <iostream>
#include <bits/stdc++.h>

const int max_n = 1e5;

int n;
int a[max_n] = {};
int mem[max_n] = {};

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::fill_n(&mem[0], n, -1);
}

int lis1(int i) {
	if (i == 0) {
		return 1;
	}
	
	if (mem[i] != -1) {
		return mem[i];
	}
	
	int res = 1;
	for (int j = i-1; j >= 0; j--) {
		if (a[j]+1 == a[i]) {
			res = std::max(res, 1+lis1(j));
		}
	}
	mem[i] = res;
	return res;
}

void solve() {
	int res = 1;
	for (int i = 0; i < n; i++) {
		res = std::max(res, lis1(i));
	}

	std::cout << res << "\n";
}

int main(int argc, char** argv) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int t = 0;
	std::cin >> t;
	while (t--) {
		input();
		solve();
	}
	return 0;
}
