#include <bits/stdc++.h>

using namespace std;

struct order
{
    int time, type, index;
};
vector<struct order> a;
int n, k, s[1000010], d[1000010], r[1000010];
long long f[1000010];


bool cmp(struct order x, struct order y)
{
    return (x.time < y.time) || (x.time == y.time && x.type < y.type);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i] >> d[i] >> r[i];
        d[i] = s[i] + d[i] + k;
        a.push_back({s[i], 1, i});
        a.push_back({d[i], 0, i});
    }
    sort(a.begin(), a.end(), cmp);
    long long res = 0;
    int i = 0;
    while (i < a.size())
    {
        int j = i + 1;
        while (j < a.size() && a[j].time == a[i].time) j++;
        for(int k = i; k < j; k++)
            if (a[k].type == 0)
            {
                res = max(res, f[a[k].index]);
            } else
            {
                f[a[k].index] = res + r[a[k].index];
            }
        i = j;
    }
    cout << res;
}
