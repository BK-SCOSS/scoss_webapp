#if 1
#include<iostream>
#include<algorithm>
using namespace std;
struct client {
	long s;
	long d;
	long long int r;
};
long n, k;
long long int* F;
long long int* M;
client* C;
int cmp(const void* a,const void* b) {
	client* x = (client*)a;
	client* y = (client*)b;
	return x->s - y->s;
}
long find(long l, long r,long v) {
	if (l == r) {
		if (C[l].s >= v)return l;
		return -1;
	}
	else {
		long mid = (l + r) / 2;
		if (C[mid].s < v)return find(mid + 1, r, v);
		else
		{
			return find(l, mid, v);
		}
	}
}
int main() {
	cin >> n >> k;
	F = new long long int[n];
	M = new long long int[n];
	C = new client[n];
	for (long i = 0;i < n;i++) {
		cin >> C[i].s >> C[i].d >> C[i].r;
		C[i].d += k;
	}
	qsort(C, n, sizeof(client), cmp);
	F[n - 1] = C[n - 1].r;
	M[n - 1] = F[n - 1];
	for (int i = n - 2;i >= 0;i--) {
		long f = find(i + 1, n - 1, C[i].s + C[i].d);
		if (f != -1)
			F[i] = C[i].r + M[f];
		else F[i] = C[i].r;
		if (F[i] > M[i + 1])M[i] = F[i];
		else M[i] = M[i + 1];
	}
	cout << M[0];
	return 0;
}
#endif