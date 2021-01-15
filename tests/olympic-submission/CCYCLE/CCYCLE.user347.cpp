#include <bits/stdc++.h>

using namespace std;

struct Matrix {
    static const int N = 64 * 3;
    int a[N][N];

    Matrix() {
        memset(a, 0, sizeof a);
    }
};

const int N = 3e4 + 4;
const int MOD = 1e9 + 7;

vector<int> a[N];
int n, L, s, t;

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int k = 1; k <= 3 * n; ++k) {
        for (int i = 1; i <= 3 * n; ++i) {
            for (int j = 1; j <= 3 * n; ++j) {
                c.a[i][j] += 1LL * a.a[i][k] * b.a[k][j] % MOD;
                if (c.a[i][j] >= MOD) c.a[i][j] -= MOD;
            }
        }
    }
    return c;
}

Matrix operator ^ (Matrix a, int p) {
    Matrix res;
    for (int i = 1; i <= 3 * n; ++i) res.a[i][i] = 1;
    while (p > 0) {
        if (p & 1) {
            res = res * a;
        }
        a = a * a;
        p >>= 1;
    }
    return res;
}

void add(int u, int v) {
    if (u > 3 * n) u -= 3 * n;
    if (v > 3 * n) v -= 3 * n;
    a[u].push_back(v);
    a[v].push_back(u);
}

int solve_mat() {
    Matrix f;
    for (int u = 1; u <= 3 * n; ++u) {
        for (int v : a[u]) {
            f.a[u][v] = 1;
        }
    }
    f = f ^ L;
    return f.a[s][t];
}

int main() {
    cin >> n >> L >> s >> t;
    for (int i = 1; i <= n; ++i) {
        add(3 * i + 1, 3 * i);
        add(3 * i + 1, 3 * i + 2);
        add(3 * i + 1, 3 * i + 3);
    }

    if (n < 64) {
        cout << solve_mat() << endl;
        return 0;
    }

    vector<int> f(3 * n + 1);
    f[s] = 1;
    for (int i = 1; i <= L; ++i) {
        vector<int> nf(f.size(), 0);
        for (int u = 1; u <= 3 * n; ++u) {
            for (int v : a[u]) {
                nf[u] += f[v];
                if (nf[u] >= MOD) nf[u] -= MOD;
            }
        }
        f.swap(nf);
    }
    cout << f[t] << endl;
    return 0;
}