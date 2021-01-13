//#include <iostream>
//#include <math.h>
//using namespace std;
//int main()
//{
//    int  k,n,t;
//    cin>>k;
//    int i;
//    int c;
//    int dem;
//    for(i=0;i<k;i++)
//    {
//        cin>>n;
//        dem=0;
//        t= n*(n+1)*(n+2);
//        c = t*t;
//        for(i=1;i<t;i++)
//        {
//            if(t%i!=0 && c%i==0)
//            {
//                dem++;
//            }
//        }
//        cout<< dem<<endl;
//    }
//}
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define lb long double
using namespace std;
int const maxn = 2e5+5;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n = n*(n+1)*(n+2);
        map<ll,ll>mp;
        mp.clear();
        for (ll i =2;i*i<=n;i++){
            while(n%i==0){
                mp[i]++;
                n/=i;
            }
        }
        if(n>2){
            mp[n]++;
        }
        ll res =1;
        ll test = 1;
        for(auto i : mp){
            res *=2*i.second+1;
            test *=i.second+1;
           // cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<(max((ll)0,res-test)-(res-1)/2)<<endl;
    }
}
