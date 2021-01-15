#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e6 + 100;
int n;
int sl[N];
vector<int> s;

void get(int x){
    for(int i = 2; i*i <= x; ++i){
        if(x%i == 0 && sl[i] == 0)
            s.push_back(i);
        while(x % i == 0)
            sl[i]++,x /= i;
    }
    if(x > 1)
    s.push_back(x),sl[x]++;
}

ll get(int x,int y,int z){
    for(auto x : s) sl[x] = 0;
    s.clear();
    get(x);
    get(y);
    get(z);
    ll a = 1,b = 1;
    for(auto x: s)
        a = a * (sl[x] + 1);
    for(auto x: s)
        b = b * (sl[x]*2 + 1);
  //  cout << a << " " << b << "\n";
    return (b+1)/2 - a;
}

int main(){
 //   freopen(".inp","r",stdin);
 //   freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        long long x;
        cin >> x;
        cout << get(x,x+1,x+2) << "\n";

    }
}
