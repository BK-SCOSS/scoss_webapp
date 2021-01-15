#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000004;
int n, test, m[N + 4], mu[N + 4], p[100][200], ans=0;
vector<int> vt;


void sang() {
    for(int i=1;i<=N-2;i++) {
        m[i] = i;
    }
    for(int i=2;i*i<=N-2;i++) {
        if(m[i] == i) {
            for(int j=i*i;j<=N-2;j+=i) {
                m[j] = i;
            }
        }
    }
    m[1] = 0;
}

void phantich(int x) {
    while(m[x] > 0) {
        if(mu[m[x]] == 0) vt.push_back(m[x]);
        mu[m[x]]++;
        x /= m[x];
    }
}

void quaylui(int i, int x, bool ok) {
    if(i == vt.size()) {
        if(x < n * (n + 1) * (n + 2) && ok) {
            //if(mp[x] == 0)
                //cout<<x<<endl;
                ans++;
            //mp[x] = 1;
        }
        return;
    }
    for(int j=0;j<=2*mu[vt[i]];j++) {
        if((long double)p[i][j] >= (long double)n*(n+1)*(n+2) / (long double)x) break;
        quaylui(i + 1, x * p[i][j], (ok || (j > mu[vt[i]])));
    }
}

void process() {
    phantich(n);
    phantich(n + 1);
    phantich(n + 2);
    for(int i=0;i<vt.size();i++) {
        for(int j=1;j<=mu[vt[i]] * 2;j++) {
            p[i][j] = p[i][j - 1] * vt[i];
        }
    }
    quaylui(0, 1, 0);
    printf("%lld\n", ans);
}

void reset() {
    for(int i=0;i<vt.size();i++) {
        mu[vt[i]] = 0;
    }
    vt.clear();
    ans = 0;
}

main() {
    //freopen("B.INP", "r", stdin);
    //freopen("B.OUT", "w", stdout);
    scanf("%lld", &test);
    sang();
    for(int i=0;i<=98;i++) {
        p[i][0] = 1;
    }
    while(test--) {
        scanf("%lld", &n);
        process();
        reset();
    }
}
