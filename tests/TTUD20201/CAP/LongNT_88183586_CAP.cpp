#include <bits/stdc++.h>
using namespace std;

int T;

int n, m;
int a[1007];
int b[1007];
map <int, int> check;
void process()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        check[a[i]] = 0;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &b[i]);
        check[b[i]] = 0;
    }
    for (int i = 1; i <= n; ++i)
        check[a[i]] = 1;
    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (check[b[i]] == 1)
        {
            res ++;
            check[b[i]] = 0;
        }
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
