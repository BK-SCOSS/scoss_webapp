#include <iostream>
#include <bits/stdc++.h>

const int max_n = 1e5;

int n;
int a[max_n] = {};

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
}

int group() {
	int k = 0;
	if (n%2 == 0) {
		k = n;
		n = n/2;
	} else {
		k = n - 1;
		n = n/2 + 1;
	}
	
	int res = 0;
	int i = 0, j = 0;
	while (j < k-1) {
		a[i] = a[j] + a[j+1];
		res = std::max(res, a[i]);
		j += 2;
		i += 1;
	}
	a[i] = a[j];
	
	return res;
}

void solve() {
	int res = 0;
	while (n > 1) {
		res += group();
	}
	std::cout << res << "\n";
}

//void in() {
//	for (int i = 0; i < n; i++) {
//		std::cout << a[i] << " ";
//	}
//	std::cout << "\n";
//}

int main(int argc, char** argv) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int t = 0;
	std::cin >> t;
	while (t--) {
		input();
		solve();
//		int res = group() + group() + group();
//		std::cout << res << "\n\n";
//		in();
	}
	return 0;
}

