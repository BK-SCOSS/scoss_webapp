#include <bits/stdc++.h>
using namespace std;
int factors(int N) {
	long long n = N*(N+1)*(N+2);
	vector<long long> div1, div2;
	for (long long i = 2; i < n; i++) {
		if (n % i == 0) div1.push_back(i);
		if (n*n % i == 0) div2.push_back(i);
	}
	return div2.size() - div1.size();
}
int main() {
	int Q, N;
	cin >> Q;
	vector<int> res(Q);
	for (int i = 0; i < Q; i++) {
		cin >> N;
		res[i] = factors(N);
	}
	for (int i: res) {
		cout << i << "\n";
	}
	return 0;
}
