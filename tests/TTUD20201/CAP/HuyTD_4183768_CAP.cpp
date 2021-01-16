#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FOrR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

int main()
{
    int T;
    cin >> T;
    vi ret;
    while (T--)
    {
        int n = 0;
        set<int> a;
        int m= 0;
        int retv = 0;
        cin >> n;
        FORL(i, 1, n)
        {
            int tmp;
            cin >> tmp;
            a.insert(tmp);
        }
        cin >> m;
        FORL(i, 1, m)
        {
            int tmp;
            cin >> tmp;
            if (a.count(tmp) > 0)
                retv++;
        }
        ret.push_back(retv);
    }
    for (auto& it: ret) cout << it << endl;
    return 0;
}