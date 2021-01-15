#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int base = 1e9 + 7;
const int N = 1e4 + 1;

//ll mt[3 * N][3 * N];

/*

struct matrix{
	int size;
	ll mat[3100][3100];

	matrix () {
		size = 0;
		memset(mat, 0, sizeof(mat));
	}
	matrix (int s) {
		for (int i = 1; i <= s; i++) {
			for (int j = 1; j <= s; j++) {
				mat[i][j] = 0;
			}
		}
	}
};



matrix ans;
*/
vector< vector<ll> > mul(vector< vector<ll> > a, vector< vector<ll> > b) {
	int n = a.size();   
	vector< vector<ll> > ans(n, vector<ll>(n, 0));	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k < n; k++) {
				ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % base) % base;	
			}
		}
	}
	return ans;
}

vector< vector<ll> > bipow(vector< vector<ll> > mt, int n) {
	if (n == 1) return mt;
	
	vector< vector<ll> > tmp = bipow(mt, n/2);
	if (n % 2 == 0) {
		return mul(tmp, tmp);
	} else {
		return mul(mul(tmp, tmp), mt);
	}
}
            

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, L, s, t;
	cin >> n >> L >> s >> t;
	//cout << n << L << s << t;
	
	vector< vector<ll> > mt(3 * n + 1, vector<ll> (3 * n + 1, 0));
	mt[1][2] = 1;
	mt[2][1] = 1;
	mt[1][3] = 1;
	mt[3][1] = 1;
	mt[3 * n][1] = 1;
	mt[1][3 * n] = 1;
	
	for (int k = 1; 3 * k + 3 < 3 * n + 1; k++) {
		mt[3 * k][3 * k + 1] = 1;
		mt[3 * k + 1][3 * k] = 1;
		mt[3 * k + 1][3 * k + 2] = 1;
		mt[3 * k + 2][3 * k + 1] = 1;
		mt[3 * k + 1][3 * k + 3] = 1;
		mt[3 * k + 3][3 * k + 1] = 1;
	}
	/*
	for (int i = 1; i < 3 * n + 1; i++) {
		for (int j = 1; j < 3 * n + 1; j++) {
			cout << mt[i][j] << ' ';
		}
		cout << '\n';
	}
	*/                 
	vector< vector<ll> > ans = bipow(mt, L);
	cout << ans[s][t];	

	return 0;
}