#include <bits/stdc++.h>

#define N 10005
using namespace std;

int n, L, s, t;
vector<int> edges[3 * N];

void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> d(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            for (int k = 0; k < a.size(); k++) {
                d[i][j] += 1LL * a[i][k] * b[k][j] % 1000000007;
                if (d[i][j] >= 1000000007) {
                    d[i][j] -= 1000000007;
                }
            }
        }
    }
    return d;
}

vector<vector<int>> f(int m, vector<vector<int> > &base) {
    if (m == 1) {
        return base;
    } 
    vector<vector<int>> c = f(m / 2, base);
    vector<vector<int>> d = multiply(c, c);
    if (m & 1) {
        return multiply(d, base);
    }
    return d;
}

int main() {
    cin >> n >> L >> s >> t;
    if (L <= 10000) {
        for (int i = 1; i < 3 * n; i += 3) {
            if (i > 1) {
                add_edge(i, i - 1);
            } else {
                add_edge(i, 3 * n);
            }
            add_edge(i, i + 1);
            add_edge(i, i + 2);
        }
        vector<vector<int>> dp(2, vector<int>(3 * n + 1, 0));
        dp[0][s] = 1;
        int p = 0;
        int q = 1;
        for (int i = 1; i <= L; i++, p ^= 1, q ^= 1) {
            for (int v = 1; v <= 3 * n; v++) {
                dp[q][v] = 0;
                for (int u : edges[v]) {
                    dp[q][v] += dp[p][u];
                    if (dp[q][v] >= 1000000007) {
                        dp[q][v] -= 1000000007;
                    }
                }
            }
        }
        cout << dp[p][t];
    } else {
        vector<vector<int> > base(3 * n, vector<int>(3 * n, 0));
        for (int i = 0; i < 3 * n; i += 3) {
            if (i > 0) {
                base[i][i - 1] = base[i - 1][i] = 1;
            } else {
                base[i][3 * n - 1] = base[3 * n - 1][i] = 1;
            }
            base[i][i + 1] = base[i + 1][i] = 1;
            base[i][i + 2] = base[i + 2][i] = 1;
        }
        cout << f(L, base)[s - 1][t - 1];
    }    
}