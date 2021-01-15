#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)

struct j{
    ll st;
    ll en;
    ll va;
};

bool condi(j t1, j t2){
    return t1.en < t2.en;
}

ll findjopt (vector<j> &js, int i,int dis){
    int l = 0;
    int r=i;
    while(l<=r){
        int m = (r+l)/2;
        if(js[i].st >= js[m].en + dis){
            if(js[i].st >= js[m+1].en+dis){
                l = m+1;
            }
            else
                return m;
            }else {
                r = m-1;
            }
    }
    return -1;
}


ll findj(vector<j> &js,int i,int dis){
    for(int k=i-1;k>=0;k--){
        if(js[i].st >= js[k].en + dis ){
            return k;
        }
    }
    return -1;
}

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<j> js;
    for(int i=0;i<n;i++){
        ll st,du,va;
        cin >> st >> du >> va;
        j t = {st,st+du,va};
        js.push_back(t);
    }
    sort(js.begin(),js.end(),condi);
    vector<ll> dp(n);
    dp[0] = js[0].va;
    for(int i=1;i<=n-1;i++){
        int j= findjopt(js,i,k);
        dp[i] = js[i].va;
        if(j != -1) dp[i] += dp[j];
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << endl;
    return 0;
}
