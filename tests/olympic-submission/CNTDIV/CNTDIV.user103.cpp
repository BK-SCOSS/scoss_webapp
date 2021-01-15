#include <iostream>
#include <cmath>

using namespace std;


int main() {

	int Q;
	cin >> Q;
	long long int N[100000];
	for (int i = 0; i < Q; i++) {
		cin >> N[i];
	}

	for (int i = 0; i < Q; i++) {
		long long int T = N[i] * (N[i] + 1) * (N[i] + 2);
		long long int T2 = T * T;
		long count = 0;
		for (int j = 2; j < T; j++) {
			if (!(T2 % j) && (T % j)) count++;
		}
		cout << count << endl;
	}

	return 0;
}