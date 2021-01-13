#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define X first
#define Y second
#define pi pair<ii, ii>

using namespace std;
const int N = 1000004;
int n, K, f[N], ans = 0;
vector<pi> vt;

priority_queue<int> q;

bool cmp(pi x, pi y) {
    if(x.X.X < y.X.X) return true;
    if(x.X.X == y.X.X) {
        return (x.X.Y > y.X.Y);
    }
    return false;
}

void process() {
    for(int i = 0; i < vt.size(); i++) {
        pi keep = vt[i];
        if(keep.X.Y == 1) {
            if(q.empty()) {
                f[keep.Y.X] = keep.Y.Y;
            } else {
                f[keep.Y.X] = keep.Y.Y + q.top();
            }
            ans = max(ans, f[keep.Y.X]);
        } else {
            q.push(f[keep.Y.X]);
        }
    }
    cout<<ans;
}

main() {
    //freopen("C.INP", "r", stdin);
    //freopen("C.OUT", "w", stdout);
    scanf("%lld%lld", &n, &K);
    for(int i=1;i<=n;i++) {
        int x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        vt.push_back(pi(ii(x, 1), ii(i, z)));
        vt.push_back(pi(ii(x + y + K - 1, 0), ii(i, z)));
    }
    sort(vt.begin(), vt.end(), cmp);
    process();
}
