#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;

int n,q;

int pr[N];
map<int,int> mp;

long long ans;

void init(){
    for (int i=2; i<N; ++i)
        pr[i] = i;
    for (int i=2; i<N; ++i)
        if (pr[i]==i)
        for (int j=i+i; j<N; j+=i)
            pr[j]=i;
}

void fact(int n, map<int,int> &mp){
    while(n>1){
        if (mp.count(pr[n])){
            mp[pr[n]]++;
        }
        else{
            mp.insert({pr[n],1});
        }
        n/=pr[n];
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>q;
    init();
    while(q--){
        cin>>n;
        mp.clear();
        ans=0;
        fact(n,mp);
        fact(n+1,mp);
        fact(n+2,mp);
        long long tmp1=1, tmp2=1;
        for (auto x:mp){
            tmp1=tmp1*(x.second +1);
            tmp2=tmp2*(2*x.second +1);
        }
        // cout<<tmp2<<' '<<tmp1<<endl;
        cout<<(tmp2-1)/2-tmp1+1<<'\n';
    }
}