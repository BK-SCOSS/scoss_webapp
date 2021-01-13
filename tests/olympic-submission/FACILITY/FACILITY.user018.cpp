#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, k;
struct KH
{
    ll s, d, r;
};
vector<KH> v(100006);
ll S, D, R;
ll money = 0;
bool myFunction(KH i, KH j)
{
    return (i.r > j.r);
}
vector<bool> dd(100006);

int main()
{
    // freopen("./input.txt", "r", stdin);
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].s >> v[i].d >> v[i].r;
    }
    sort(v.begin(), v.begin() + n, myFunction);
    for (ll i = 0; i < n; i++)
    {
        // cout << v[i].s << " " << v[i].d + k << " " << v[i].r << endl;
        if (dd[v[i].s] == false && dd[v[i].s + v[i].d + k - 1] == false)
        {
            money += v[i].r;
            fill(dd.begin() + v[i].s, dd.begin() + v[i].s + v[i].d + k, true);
        }
    }
    cout << money << endl;
}