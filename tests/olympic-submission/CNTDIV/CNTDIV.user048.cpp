#include <iostream>

using namespace std;

int main()
{
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		long long T = N * (N + 1) * (N + 2);
		long long T2 = T * T;
		int count = 0;
		for (int i = 2; i <= T; i++)
			if (T%i != 0 && T2%i == 0) count++;
		cout << count << endl;	
	}
}

