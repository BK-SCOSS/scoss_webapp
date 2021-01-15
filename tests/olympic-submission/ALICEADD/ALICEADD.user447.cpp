#include<bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long n;
    cin >> n;
    while(n--) {
        unsigned long long a, b, c;
        cin>>a>>b;
        unsigned long long a1, b1, c1;
        a1 = a%10;
        b1 = b%10;
        c1 = a1 + b1;
        a /= 10;
        b /= 10;
        c = a + b;
        if (c == 0) cout << c1;
        else {
            if (c1 < 10) {
                cout << c;
                cout << c1;
            }
            else {
                cout << c + 1;
                cout << c1 % 10;
            }
        }
        cout<<endl;
    }
    return 0;
}
