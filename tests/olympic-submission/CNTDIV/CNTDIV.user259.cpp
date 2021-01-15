#include<bits/stdc++.h>

using namespace std;

#define ff(i,a,b) for(int i = (a); i <= (b); ++i)

typedef long long ll;

const int N = 1000000 + 10;

int hasDivisor[N];
vector<int> divisor[N], cnt[N];

void init(int n) {
    ff(i, 2, n) hasDivisor[i] = i;

    ff(i, 2, n)
    if (hasDivisor[i] == i) {
        ff(j, 1, n/i) {
            divisor[i * j].push_back(i);
            hasDivisor[i * j] = i;
        }
    }

    ff(i, 2, n) {
        for(int j : divisor[i]) {
            cnt[i].push_back(0);
            int p = i;
            while (p % j == 0) {
                cnt[i].back()++;
                p /= j;
            }
        }
    }
}

map<int, int> cntDivisors;
vector<int> divisorVec;
vector<int> cntVec;

ll cal(int x, ll y, ll t) {
    if (y > t) return 0;
    if (x == cntVec.size()) {
        //cout << y << endl;
        return 1;
    }
    ll res = 0;
    ll p = 1;
    ff(i, 0, cntVec[x] * 2) {
        //cout << x << " " << p << " " << y << endl;
        if (y <= t / p) {
            res += cal(x + 1, y * p, t);
        }
        else break;
        p *= divisorVec[x];
    }
    return res;
}

ll getResult(ll n) {
    cntDivisors.clear();
    ff(i, n, n + 2) {
        ff(j, 0, (int) divisor[i].size() - 1) {
            //cout << i << " " << divisor[i][j] << " " << cnt[i][j] << endl;
            cntDivisors[divisor[i][j]] += cnt[i][j];
        }
    }

    divisorVec.clear();
    cntVec.clear();
    ll res = -1;
    for (auto i : cntDivisors) {
        res *= i.second + 1;
        divisorVec.push_back(i.first);
        cntVec.push_back(i.second);
        //cout << i.first << " " << i.second << endl;
    }
    //cout << res << endl;
    ll t = n * (n + 1) * (n + 2);
    //cout << t << endl;
    res += cal(0, 1, t);
    return res;
}

int main() {
    init(1000000);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << getResult(n) << endl;
    }
}
