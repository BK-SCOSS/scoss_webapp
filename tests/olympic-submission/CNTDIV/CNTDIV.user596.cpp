#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+8;
vector<int> f;
int p[MAXN];

void factorize(int n) {
	memset(p, true, sizeof p);
	f = vector<int>();
	int tmp0 = n;
	int tmp1 = n+1;
	int tmp2 = n+2;
	int cnt;
	for(int i = 2; i <= sqrt(n+2); i++) {
		if(p[i]) {
			for(int j = i; j <= sqrt(n+2); j+=i)
				p[j] = false;
		
			cnt = 0;
			while(tmp0%i == 0) {
				cnt++;
				tmp0 /= i;
			}
			while(tmp1%i == 0) {
				cnt++;
				tmp1 /= i;
			}
			while(tmp2%i == 0) {
				cnt++;
				tmp2 /= i;
			}
			if(cnt != 0)
				f.push_back(cnt);
		}
	}
	if(tmp0 != 1)
		f.push_back(1);
	if(tmp1 != 1 && tmp0 != tmp1)
		f.push_back(1);
	if(tmp2 != 1 && tmp0 != tmp2 && tmp1 != tmp2)
		f.push_back(1);
}

int main() {
	int Q;
	cin >> Q;
	int N;
	while(Q--) {
		cin >> N;
		factorize(N);
		long long a = 1;
		long long b = 1;
		for(auto x: f) {
			a = a*(2ll*x+1);
			b = b*(1ll*x+1);
		}
		cout << (a-1 - 2*(b-1))/2 << endl;
	}
	return 0;
}