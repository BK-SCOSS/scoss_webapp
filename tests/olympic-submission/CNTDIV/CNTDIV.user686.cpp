#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int Q, N;
int a[10005];
int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> N;
		int d = 0;
		long long T = N * (N + 1) * (N + 2);
		for (int i = 2; i < T; i++)
			if (T * T % i == 0 && T%i!=0)
				d += 1;
		cout << d << endl;
	}
	return 0;
}
