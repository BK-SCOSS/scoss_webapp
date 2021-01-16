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

int merge(vector<int> &a)
{
    int length = a.size();
    int cost = 0;
    vi ret;
    for (int i = 0; i < length - 1; i = i + 2)
    {
        int thiscost = a[i] + a[i + 1];
        ret.push_back(thiscost);
        cost = max(cost, thiscost);
    }
    if (length % 2 == 1)
        ret.push_back(a[length - 1]);
    a.clear();
    a = ret;
    return cost;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n = 0;
        cin >> n;
        vi a;
        for(int i = 0; i < n;i++) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        int start = 0;
        while (a.size() > 1)
        {
            start += merge(a);
        }
        cout << start << endl;
    }
    return 0;
}