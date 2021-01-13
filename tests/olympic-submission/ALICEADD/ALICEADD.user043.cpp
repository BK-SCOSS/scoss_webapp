//comment, comment, just comment :)
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= _b; --i)
#define REP(i, a) for(int i = 0, _a = a; i < _a; ++ i)
#define llint long long
#define sz(x) (x.size())
#define fi first
#define se second
#define mp make_pair
#define LL(x) (x << 1)
#define RR(x) ((x << 1) + 1)
#define endl '\n'
#define db(x) cout << #x << " = " << x << endl;
#define dbs(x, y) cout << #x << " = " << x << " | " << #y << " = " << y << endl;

// SEE ME BEFORE SUBMIT !!!
#define TASKNAME "sx"

void Openfile() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen(TASKNAME".inp", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
	#endif
}

const int maxN = 1e5 + 5;
const int maxM = 1e6 + 5;
const llint INF = 1e9;
const int cs = 9;

typedef vector<llint> big;

int N;
big A, B;

inline string toString(int a) {
	stringstream ss;
	ss << a;
	string res;
	ss >> res;
	return res;
}

inline string toString(big a) {
	string res = "";
	string cur;
	int d = sz(a);
	REP(i, d) {
		cur = toString(a[i]);
		if (i != d - 1) {
			while (sz(cur) < cs) cur = "0" + cur;
		}
		res = cur + res;
	}
	return res;
}

inline int toInt(string a) {
	stringstream ss;
	ss << a;
	int res;
	ss >> res;
	return res;
}

void getBig(big &a) {
	string s;
	cin >> s;
	a.clear();
	string t = "";
	int cur = 0;
	FORD(i, sz(s) - 1, 0) {
		t = s[i] + t;
		++cur;
		if (i == 0 || cur == cs) {
			a.push_back(toInt(t));
			cur = 0;
			t = "";
		}
	}
}

big operator + (big a, big b) {
	while (sz(a) < sz(b)) a.push_back(0);
	while (sz(a) > sz(b)) b.push_back(0);
	llint cr = 0;
	REP(i, sz(a)) {
		cr = cr + a[i] + b[i];
		a[i] = cr % INF;
		cr /= INF;
	}

	if (cr) a.push_back(cr);
	return a;
}

big operator - (big a, big b) {
	//a > b
	while (sz(a) < sz(b)) a.push_back(0);
	while (sz(b) < sz(a)) b.push_back(0);
	llint cr = 0;
	REP(i, sz(a)) {
		cr = a[i] - b[i] - cr;
		if (cr < 0) {
			a[i] = cr + INF;
			cr = 1;
		}
		else {
			a[i] = cr;
			cr = 0;
		}
	}
	while (sz(a) > 1 && a.back() == 0) a.pop_back();
	return a;
}

big operator * (big a, big b) {
	big res; res.clear();
	REP(i, sz(a)) {
		llint cr = 0;
		REP(j, sz(b)) {
			cr = cr + a[i] * b[j];
			if (i + j < sz(res)) {
				res[i + j] = res[i + j] + cr % INF;
			}
			else {
				res.push_back(cr % INF);
			}

			cr /= INF;
		}
		if (cr) {
			if (i + sz(b) < sz(res)) {
				res[i + sz(b)] += cr;
			}
			else res.push_back(cr);
		}
	}
	llint cr = 0;
	REP(i, sz(res)) {
		cr = cr + res[i];
		res[i] = cr % INF;
		cr /= INF;
	}
	if (cr) res.push_back(cr);
	return res;
}

bool operator < (big a, big b) {
	if (sz(a) != sz(b)) return sz(a) < sz(b);
	FORD(i, sz(a) - 1, 0) {
		if (a[i] != b[i]) {
			return a[i] < b[i];
		}
	}
	return false;
}

void Enter() {
	getBig(A);
	getBig(B);
}

void Solve() {
	cout << toString(A + B) << endl;
	//if (A < B) cout << "-" << toString(B - A) << endl;
	//else cout << toString(A - B) << endl;
	//cout << toString(A * B) << endl;
}

int main() {
	//Openfile();
    int t ;
    cin >> t;
    while (t--){
        	Enter();
	Solve();
    }

	return 0;
}
