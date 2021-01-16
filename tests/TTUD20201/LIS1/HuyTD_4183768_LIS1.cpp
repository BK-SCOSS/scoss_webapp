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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n = 0;
        int best = 0;
        vi a;
        cin >> n;
        int mark[10000] = {0};
        FORL(i, 1, n)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        FOR(i, n -1)
        {
            vi tmp;
            tmp.push_back(a[i]);
            FORL(j, i + 1, n-1) {
                if (tmp.back() == a[j] -1) tmp.push_back(a[j]);
            }
            best = max(best, tmp.size());
        }
        cout << best << endl;
    }
    return 0;
}