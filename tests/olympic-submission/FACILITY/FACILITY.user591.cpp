#include <bits/stdc++.h>
#define N 1000007
using namespace std;


struct client
{
    long long start;
    long long finish;
    long long price;
};

struct _time
{
    int id;
    long long val;
    int type;
};
bool timecompare(_time x, _time y)
{
    return x.val < y.val; 
}
bool clientcompare(client a, client b)
{
    return a.start < b.start;
}
client a[1000007];
long long TREE[3000007];
int n;
long long k;
long long f[1000007];

long long getTree(int i)
{
    long long res = TREE[i];
    while (i > 0)
    {
        res = max(res, TREE[i]);
        i-=i&-i;
    }
    return res;
}
void updateTree(int i, long long val)
{
    while (i < 3000007)
    {
        TREE[i] = max(TREE[i], val);
        i+=i&-i;
    }
}
int main()
{

    scanf("%d%lli", &n, &k);
    for (int i=1; i<=n; ++i)
    {
        long long x, y, z;
        scanf("%lli%lli%lli", &x, &y, &z);
        a[i].start = x;
        a[i].finish = x + y + k;
        a[i].price = z;
    }

    vector <_time> v;
    for (int i=1; i<=n; ++i)
    {
        _time t;
        t.id = i;
        t.val = a[i].start;
        t.type = 1;
        v.push_back(t);
        t.val = a[i].finish;
        t.type = 0;
        v.push_back(t);
    }
    sort (v.begin(), v.end(), timecompare);

    int j = 1;
    a[v[0].id].start = 1;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i].val > v[i-1].val)
        {
            j++;
            if (v[i].type) a[v[i].id].start = j*1LL;
            else a[v[i].id].finish = j*1LL;
        }
        else
        {
            if (v[i].type) a[v[i].id].start = j*1LL;
            else a[v[i].id].finish = j*1LL;
        } 
    }
    sort (a+1, a+n+1, clientcompare);
    long long res = 0;
    for (int i=1; i<=n; ++i)
    {
        f[i] = getTree(a[i].start) + a[i].price;
        res = max(res, f[i]);
        updateTree(a[i].finish, f[i]);
    }
    printf("%lli", res);
}