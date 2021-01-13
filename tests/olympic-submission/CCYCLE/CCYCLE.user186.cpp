#include <bits/stdc++.h>

#define MAX_INT 1000000007
#define maxl 10007
#define ln length()
#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,a,b) for(int i = a; i >= b; i--)
typedef long long ll;
using namespace std;

ll n, L, s, t;
ll pathlen = 0, cnt = 0;
vector<int> adj[maxl];

void TRY(ll k) {
    for (auto nxt: adj[k]) {
        pathlen++;
        if (pathlen == L) {
            if (nxt == t) cnt++;
        } else TRY(nxt);
        pathlen--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> L >> s >> t;
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(n*3);
    adj[n*3].push_back(n*3-2);
    adj[n*3].push_back(1);
    for (ll i = 2; i < n*3; i++) {
        switch (i % 3)
        {
        case 0:
            adj[i].push_back(i-2);
            adj[i].push_back(i+1);
            break;
        case 1:
            adj[i].push_back(i-1);
            adj[i].push_back(i+1);
            adj[i].push_back(i+2);
            break;
        
        default:
            adj[i].push_back(i-1);
            break;
        } 
    }
    // for (int i = 0; i <= n*3; i++) {
    //     cout << "Point " << i << ": ";
    //     for (auto it: adj[i])
    //         cout << it << ' ';
    //     cout << endl;
    // }
    TRY(s);
    cout << cnt;
}