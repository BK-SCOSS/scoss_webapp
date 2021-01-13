#if 1
#include<iostream>
using namespace std;
long n, L, s, t;
long** F;
long find(long s,long l) {
	if (F[s][l] != -1)return F[s][l];
	if (l == 0 && s != t)return 0;
	if (s % 3 == 2)F[s][l] = find(s - 1, l - 1);
	else if (s % 3 == 0) {
		if (s == 3 * n) {
			F[s][l] = find(s - 2, l - 1) + find(1, l - 1);
		}
		else F[s][l] = find(s - 2, l - 1) + find(s + 1, l - 1);
	}
	else
	{
		if (s == 1) {
			F[s][l] = find(2, l - 1) + find(3, l - 1) + find(3 * n, l - 1);
		}
		else F[s][l] = find(s - 1, l - 1) + find(s + 1, l - 1) + find(s + 2, l - 1);
	}return F[s][l] % 1000000007;
}
int main() {
	cin >> n >> L >> s >> t;
	F = new long* [3 * n + 1];
	for (long i = 0;i <= 3 * n;i++) {
		F[i] = new long[L + 1];
	}
	for (long i = 0;i <= 3 * n;i++) {
		for (long j = 0;j <= L;j++) {
			F[i][j] = -1;
		}
	}F[t][0] = 1;
	cout << find(s, L);
	return 0;
}
#endif