#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+2;
long long n;
long long dp[N],sdp[N];
vector<pair<long long,pair<long long,long long>>> a;
int main(){
    long long K;
    cin >> n >> K;
    a.push_back(make_pair(0,make_pair(0,0)));
    for(long long i=1; i<=n; ++i){
        long long s,d,r;
        cin >> s >> d >> r;
        long long e=s+d+K;
        a.push_back(make_pair(e,make_pair(s,r)));
    }
    sort(a.begin(),a.end());
    for(long long i=1; i<=n; ++i){
        long long l=0,r=i,mid,p=0;
        while(l<=r){
            mid=(l+r)>>1;
            if (a[mid].first<=a[i].second.first){
                p=mid;
                l=mid+1;
            } else r=mid-1;
        }
        dp[i]=sdp[p]+a[i].second.second;
        sdp[i]=max(sdp[i-1],dp[i]);
    }
    cout << sdp[n];
    return 0;
}




