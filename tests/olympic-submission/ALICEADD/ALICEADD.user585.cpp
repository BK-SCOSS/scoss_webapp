#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e5+10
//#define int long long
void solve(){
    string a, b;
    cin>>a>>b;
    int i = a.size() - 1, j = b.size() - 1;
    string s ="";
    int c = 0;
    while(i >= 0 && j >= 0){
        int x = a[i] - '0', y= b[j] -'0';
        int z = x + y + c;
//        cout<<s<<endl;
//        cout<<x<<' '<<y<<' '<<z<<endl;
        c = z/10;
        s = char(48 + z%10) + s;
        i--;
        j--;
    }
    if(i >= 0){
        int x = a[i] -'0';
        int z = x + c;
        c = z / 10;
        s = char(48 + z%10) + s;
        i--;
    }
    else if(j >= 0){
        int y = b[j] - '0';
        int z = y + c;
        c = z/10;
        s = char(48 + z%10) + s;
        j--;
    }
    if( c!= 0) s = to_string(c) + s;
    cout<<s<<endl;
}
//#undef int
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 0x3F
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}