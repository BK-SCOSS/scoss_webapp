#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define x first
#define y second

const int N = 1000005;

int minp[N];
vector<ii> nai;
int dem = 0;
int cur = 1;
int n;
int t;


void naive(int k) {
	if (cur > t)
		return;
	int tmp = 1;
	for (int i = 0; i <= nai[k].y; i++) {
		if (tmp > t) 
			break;
		if (t / cur < tmp)
			return;
		cur *= tmp;
		if (k == nai.size() - 1) {
			// cout << k << ' ' << cur << ' ' << i << endl;
			if (cur < t && t % cur != 0)
				dem++;
		} else {
			naive(k + 1);
		}
		cur /= tmp;
		if (t / tmp < nai[k].x)
			break;
		tmp *= nai[k].x;
	}

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	for (int i = 2; i < N; i++) {
		if (minp[i] == 0) {
			minp[i] = i;
			if (i * i >= N)
				break;
			for (int j = i * i; j < N; j += i)
				if (minp[j] == 0)
					minp[j] = i;
		}
	}
	for (int i = 2; i < N; i++) {
		if (minp[i] == 0)
			minp[i] = i;
	}

	int ntest;
	cin >> ntest;

	while (ntest--) {
		cin >> n;
		t = n * (n + 1) * (n + 2);
		map<int, int> cnt;
		for (int i = 0; i < 3; i++) {
			int nn = n + i;
			while (nn > 1) {
				cnt[minp[nn]]++;
				nn /= minp[nn];
			}
		} 

		// for (auto u : cnt) {
		// 	nai.push_back({u.x, 2 * u.y});
		// }

		// naive(0);

		// cout << dem << '\n';

		// nai.clear();
		// dem = 0;
		// cur = 1;

		int ans1 = 1;
		int ans2 = 1;

		for (auto u : cnt) {
			ans1 *= (u.y + 1);
			ans2 *= (2 * u.y + 1);
		}

		ans2 = ans2 / 2 + 1;

		cout << ans2 - ans1 << "\n";
	}

	return 0;
}