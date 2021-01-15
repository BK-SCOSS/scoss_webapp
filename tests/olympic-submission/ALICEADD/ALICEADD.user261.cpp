#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    unsigned long long a, b, c, d, e, f, x, y;
    cin>>t;
    while (t--){
        cin>>a>>b;
        c = a/10; d = a%10;
        e = b/10; f = b%10;
        x = (c+e) + (d+f)/10;
        y = (d+f)%10;
        if (x>0) cout<<x;
        cout<<y<<endl;
    }
    return 0;
}
