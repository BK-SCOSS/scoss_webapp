#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1;
const int MOD=1e9+7;
const int bm=1;
int n,m;

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    unsigned long long a,b;
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if ( a/10+b/10+((a%10+b%10)>9) ) cout<<a/10+b/10+((a%10+b%10)>9);
        cout<<(a%10+b%10)%10<<endl;
    }

}
