#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+6;

typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

int n,k;
ppi a[N];

int cp[2*N];
pii _cp[2*N];

long long ans, bit[N];

void compress(){
    sort(_cp+1,_cp+1+2*n);
    int cnt=0;
    for (int i=1; i<=2*n; ++i){
        if (_cp[i].first != _cp[i-1].first) cnt++;
        cp[_cp[i].second] = cnt;
    }
}
inline bool cmp(ppi A, ppi B){
    if (A.first.second != B.first.second)
        return A.first.second < B.first.second;
    return A.first.first < B.first.first;
}

inline void update(int x, long long val){
    for (; x <2*n+1 ; x+=x&-x)
        bit[x] = max(bit[x], val);
}
inline long long get(int x){
    long long ans=0;
    for (; x>0; x-=x&-x)
        ans = max(ans, bit[x]);
    return ans;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; ++i){
        cin>>a[i].first.first>>a[i].first.second>>a[i].second;
        a[i].first.second += a[i].first.first;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1; i<=n; ++i){
        _cp[i] = pii(a[i].first.first,i);
        _cp[n+i] = pii(a[i].first.second + k, n+i);
    }
    compress();
    for (int i=1; i<=n; ++i){
        long long tmp = get(cp[i]) + a[i].second;
        ans = max(ans, tmp);
        update(cp[n+i], tmp);
        // cout<<a[i].first.first<<' '<<a[i].first.second<<' '<<a[i].second<<endl;
        // cout<<cp[i]<<' '<<cp[n+i]<<endl;
        // cout<<tmp<<endl;
        // cout<<"---"<<endl;
    }
    cout<<ans;
}