
#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fo(i, x, y) for(int i=x; i<=y; i++)
#define rfo(i, x, y) for(int i=x; i>=y; i--)
using namespace std;
const ll oo=1e18;
string operator +(string x, string y)
{
    while(x.size()<y.size()) x='0'+x;
    while(y.size()<x.size()) y='0'+y;
    int cr=0;
    string res;
    for(int i=(int)x.size()-1; i>=0; i--){
        int t=x[i]-'0'+y[i]-'0'+cr;
        res=(char)(t%10+'0')+res;
        cr=t/10;
    }
    if(cr>0) res='1'+res;
    return res;
}
main()
{
	ios_base::sync_with_stdio(false); cin.tie();
    //freopen("read.inp", "r", stdin);
	//freopen("read.out", "w", stdout);
	int test=1;
	cin>>test;
	while(test--){
        string x, y;
        cin>>x>>y;
        string res=x+y;
        cout<<res<<endl;
	}
}
