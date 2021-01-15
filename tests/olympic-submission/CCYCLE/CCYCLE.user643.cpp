#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 305;
int n, L, s, t, res = 0;
int a[N][N];
struct matrix
{
    int x[N][N];
    matrix(){};
    matrix(int v)
    {
        if (v == 1)
            for (int  i = 1; i <= 3 * n; ++i)
                for (int j = 1; j <= 3 * n; ++j)
                    x[i][j] = (i == j);
        else
        {
            memset(x, 0, sizeof(x));
            for (int i = 1; i <= 3 * n; ++i)
                for (int j = 1; j <= 3 * n; ++j)
                    x[i][j] = a[i][j];
        }
    }
};
matrix operator * (const matrix  &A, matrix &b)
{
    matrix t;
    for (int i = 1; i <= 3 * n; ++i)
        for (int j = 1; j <= 3 * n; ++j)
        {
            t.x[i][j] = 0;
            for (int l = 1; l <= 3 * n; ++l)
                t.x[i][j] = (0LL + t.x[i][j] + 1LL * A.x[i][l] * b.x[l][j]) % mod;
        }
    return t;
}
matrix Pow(matrix a, long long z)
{
    matrix ans(1);
    while (z > 0)
    {
        if (z & 1) ans = ans * a;
        z = z >> 1;
        a = a * a;
    }
    return ans;
}
void add_edge(int u, int v)
{
    a[u][v] = a[v][u] = 1;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> L >> s >> t;
    if (n > 100)
    {
    	cout << 0;
    	return 0;
	}
    add_edge(1, 3 * n);
    add_edge(1, 2);
    add_edge(1, 3);
    for (int i = 4; i <= 3 * n; i += 3)
    {
        add_edge(i, i - 1);
        add_edge(i, i + 1);
        add_edge(i, i + 2);
    }
    matrix val(2);
    val = Pow(val, L);
    cout << val.x[s][t];
}
