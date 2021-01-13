#include<bits/stdc++.h>
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long a,b;
    cin >> a >> b;

    int a1 = a%10;
    int b1=b%10;
    a/=10;
    b/=10;
    int c2=(a1+b1)%10;
    long long c1=(a1+b1)/10;
    c1+=a+b;
    if(c1 > 0) cout<<c1;
    cout << c2 << "\n";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
