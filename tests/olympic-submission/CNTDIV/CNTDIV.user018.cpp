#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <cmath>
using namespace std;
typedef int ll;
const ll MAXSANG = 1000002;
ll q, n;
bool snt[MAXSANG];
vector<ll> v;
ll c = 0;
void sangnt()
{
    // Thuật toán sàng nguyên tố
    // Nếu một số là số nguyên tố, thì tất cả các bội của nó không phải số nguyên tố
    for (int i = 2; i <= MAXSANG; i++)
    {
        if (snt[i] == false)
        {
            v.push_back(i);
            c++;
            for (int j = 2 * i; j <= MAXSANG; j += i)
            {
                snt[j] = true;
            }
        }
    }
}
int main()
{
    sangnt();
    cin >> q;
    for (ll i = 1; i <= q; i++)
    {
        cin >> n;
        map<int, int> m;
        ll j = 0;
        ll x = n, y = n + 1, z = n + 2;
        while (j != v.size() && v[j] <= z)
        {
            while (x % v[j] == 0)
            {
                m[v[j]]++;
                x /= v[j];
            }
            while (y % v[j] == 0)
            {
                m[v[j]]++;
                y /= v[j];
            }
            while (z % v[j] == 0)
            {
                m[v[j]]++;
                z /= v[j];
            }
            j++;
            x = n, y = n + 1, z = n + 2;
        }
        map<int, int>::iterator it;
        ll T = 1, T2 = 1;
        for (it = m.begin(); it != m.end(); it++)
        {
            T *= it->second + 1;
            T2 *= (it->second) * 2 + 1;
        }
        cout << (T2 - 1) / 2 - T + 1 << endl;
    }
    // cin >> Q;
    // for (ll i = 1; i <= Q; i++)
    // {
    //     cin >> N;
    //     ll T = N * (N + 1) * (N + 2);
    //     ll c = 0;

    // }
}