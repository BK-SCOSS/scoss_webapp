#include <iostream>
#include <algorithm>
using namespace std;
struct manner{
	unsigned long long int s;
	unsigned long long int d;
	unsigned long long int r;
	unsigned long long int d1;
	unsigned long long int d2;
};
bool sub(manner x, manner y) {
	return x.s <= y.s;
}

long int sol(manner *man, unsigned long long int n, unsigned long long int p) {
	if(p == 0) return man[0].r;
	else if(man[p].s < man[0].d2) return man[p].r;
	else 
	{
		long int max;
		max = man[0].r + man[p].r;
		for(long int i = p-1; i >= 0; i--) {
			if(man[p].s >= man[i].d2) {
				if(max < sol(man,n,i) + man[p].r) max = sol(man,n,i) + man[p].r;
			}
		}
		return max;
	}
}

int main() {
	unsigned long long int n, K, max, fin;
	cin >> n >> K;
	struct manner *man;
	man = new manner[n*sizeof(manner)];
	for(long int i = 0; i < n; i++) {
		cin >> man[i].s >> man[i].d >> man[i].r;
		man[i].d1 = man[i].s + man[i].d -1;
		man[i].d2 = man[i].d1 + K;
	}
	sort(man, man+n, sub);
	max = 0;
	for(long int i = 0; i < n; i++) {
		if(max < sol(man,n,i)) max = sol(man,n,i);
	}
	cout << max;
	return 0;
}
