#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

ll n, K;
ll s[maxn], d[maxn], r[maxn];
ll ss[maxn], dd[maxn], rr[maxn];
ii a[maxn];
ll dp[maxn];
vector<int> g[maxn];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> n >> K;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        cin >> ss[i] >> dd[i] >> rr[i];
        a[i].fi = ss[i];
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        // cout << a[i].se << " ";
        s[i] = ss[a[i].se];
        d[i] = dd[a[i].se] + K;
        r[i] = rr[a[i].se]; 
        // cout << s[i] << " " << d[i] << "  " << r[i] << endl;
    }

    // set<int> myset;
    // myset.insert(1);
    // for(int i = 2; i <= n; i++) {
    //     // cout << i;
    //     vector<int> del;
    //     for(auto j = myset.begin(); j != myset.end(); j++) {
    //         int tmp = *j;
    //         // cout << tmp;
    //         if(s[tmp] + d[tmp] <= s[i]) {
    //             g[i].push_back(tmp);
    //             del.push_back(tmp);
    //         }
    //     }
    //     for(auto j: del) myset.erase(j);
    //     myset.insert(i);
    // }
    // for(int i = 2; i <= n; i++) {
    //     for(auto j: g[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // dp[1] = r[1];
    
        // cout << i << endl;  
        for(int j = 1; j <= n; j++) {
            dp[j] = r[j];
            for(int k = 1; k < j; k++){
                if(s[k] + d[k] <= s[j]) dp[j] = max(dp[j], dp[k] + r[j]);
            }
        // cout << dp[j] << " ";
        }
        // cout << endl;
    

    ll ans = -1;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;       
}
