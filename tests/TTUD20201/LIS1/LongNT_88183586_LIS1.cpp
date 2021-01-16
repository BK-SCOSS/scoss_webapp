#include <bits/stdc++.h>
using namespace std;

int T;

int n, m;
int a[100007];
int f[100007];
map <int, int> check;
void process()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        check[a[i] - 1] = 0;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = max(1, check[a[i] - 1] + 1);
        check[a[i]] = max(check[a[i]], f[i]);
        res = max(res, f[i]);
    }
    printf("%d\n", res);
}


int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        process();
    }
}
