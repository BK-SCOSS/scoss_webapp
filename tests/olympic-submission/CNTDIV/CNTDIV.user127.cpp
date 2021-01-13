#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

vector<int> tmp;
ll q, n, t, tt, ch, ans, r;
int cnt[maxn];
vector<int> factorize(int x) {
    vector<int> res;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            res.push_back(i);
            x /= i;
        }
    }
    if (x != 1) {
        res.push_back(x);
    }
    return res;
}

void dem(int u) {
    if(u == tmp.size()) {
        if(r < t && (t % r != 0)) {
            // cout << r << " " << ans << endl;
            ans++;
        }
        return;
    }
    for(int i = 0; i <= 2 * cnt[tmp[u]]; i++) {
        // if(i >= cnt[tmp[u]] + 1) {
        //     ch = 1;
        // }
        // cout << i << " " << u << endl;
        // cout << i << endl;
        // cout << 'j' << endl;

        if(i != 0) {
            if(r > t / pow(tmp[u], i)) {
                break;
            }
        }
        if(i != 0) r *= pow(tmp[u], i);
        dem(u+1);
        if(i != 0) r /= pow(tmp[u], i);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> q;
    // cout << pow(10, 0);
    while(q--) {
        cin >> n;
        tmp.clear();
        ch = 0;
        ans = 0;
        t = n * (n + 1) * (n + 2);
        // tt = t * t;
        set<int> s;
        vector<int> a = factorize(n);
        vector<int> b = factorize(n + 1);
        vector<int> c = factorize(n + 2);
        for(auto i : a) {
            cnt[i]++;
            s.insert(i);
        }
        for(auto i : b) {
            cnt[i]++;
            s.insert(i);
        }
        for(auto i : c) {
            cnt[i]++;
            s.insert(i);
        }
        
        for(auto i = s.begin(); i != s.end(); i++) {
            tmp.push_back(*i);
        }
        // for(auto i: tmp) {
        //     cout << i << " ";
        //     cout << cnt[i] << " ";
        // }
        r = 1;
        dem(0);

        // cout << endl;
        // clear cnt
        for(auto i : a) {
            cnt[i] = 0;
        }
        for(auto i : b) {
            cnt[i] = 0;
        }
        for(auto i : c) {
            cnt[i] = 0;
        }
        cout << ans << endl;

    }
    return 0;       
}
