#include <bits/stdc++.h>
using namespace std;
unsigned long long n,a,b, a1, b1 ,a0,b0,c0,c1;
int main() {
    cin >>n;
    for(int i =0; i<n;i++){
        cin >> a >>b;
        a0 = a %10;
        a1 = (a-a0)/10;
        b0 = b % 10;
        b1 = (b-b0) /10;
        c0 =(a0+b0) %10;
        c1 = (a0+b0-c0) /10;
        c1 = a1+ b1 + c1;
        if(c1> 0) cout << c1;
        cout << c0 <<endl;
    }

    return 0;
}
