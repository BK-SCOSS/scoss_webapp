#include <iostream>

using namespace std;

int main() {
	unsigned int Q;
	unsigned long int N;
	unsigned long long int T;
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		fflush(stdin);
		int dem = 0;
		unsigned long long int K;
		cin >> N;
		T = N * (N + 1) * (N + 2);
		K = T * T;
		for (int j = 1; j <= T; j++) {
			if (K % j == 0 && T % j != 0) {
				dem++;
			}
		}
		cout << dem << endl;
	}
	return 0;
}