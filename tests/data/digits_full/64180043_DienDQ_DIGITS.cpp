#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

int t;
long long n;
int a[8];
bool ok[10];
int res = 0;

//H U S T O I C
void dq(int x){
    if(x == 8){
        int u = a[1] * 1000  + a[2] * 100  + a[3] * 10 + a[4];
        int v = a[3]*10000 + a[5]*1000 + a[6]*100 + a[7]*10 + a[4];
        if(u+v == n) ++res;//cout << u << " " << v << " " << u+v << "\n";
        return;
    }
    for(int i = (x == 1 || x == 3); i <= 9; ++i){
        if(ok[i]) continue;
        ok[i] = 1;
        a[x] = i;
        dq(x+1);
        ok[i] = 0;
    }
}

main(){
  //  freopen(".inp","r",stdin);
   // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        memset(ok,0,sizeof(ok));
        res = 0;
        dq(1);
        cout << res << "\n";
    }
}
