#include <bits/stdc++.h>

using namespace std;


int const N = 1e6 + 5;

int d[N];

void add_prime_divisiors(map< int, int > &prime_divisiors, int n) {
	while (n > 1) {
		int largest_divisior = d[n];
		while (n % largest_divisior == 0) {
			prime_divisiors[largest_divisior]++;
			n /= largest_divisior;
		}
	}
}

int main() {
	for (int i = 2; i < N; i++) {
		if (d[i]) {
			continue;
		}
		for (int j = i; j < N; j += i) {
			d[j] = i;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map< int, int > prime_divisiors;
		add_prime_divisiors(prime_divisiors, n);
		add_prime_divisiors(prime_divisiors, n + 1);
		add_prime_divisiors(prime_divisiors, n + 2);
		long long total_square = 1;
		long long total = 1;
		for (auto v : prime_divisiors) {
			total_square = total_square * (v.second * 2 + 1);
			total = total * (v.second + 1);
		}

		cout << (total_square + 1) / 2 - total << endl;

	}
}