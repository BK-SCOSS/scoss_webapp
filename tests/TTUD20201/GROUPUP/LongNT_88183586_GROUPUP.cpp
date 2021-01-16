#include <bits/stdc++.h>
using namespace std;

int T;

int n;
int x;
void process()
{
    scanf("%d", &n);
    vector <int> a;
    vector <int> b;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        a.push_back(x);
    }
    int res = 0;
    // int j = 1;
    while (a.size() > 1)
    // while (j < 3)
    {
        int tmp = 0;
        for (int i = 1; i < a.size(); i+=2)
        {
            x = a[i] + a[i - 1];
            b.push_back(x);
            tmp = max(tmp, x);
        }
        if (a.size()%2)
        {
            b.push_back(a.back());
        }
        res += tmp;
        a = b;
        b.clear();
        // for (int i = 0; i < a.size(); ++i)
        // {
        //     printf("%d ", a[i]);
        // }
        // printf("\n");
        // j ++;
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
