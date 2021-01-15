#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    unsigned long long a,b;
    while(n>0){
        cin>>a>>b;
        int a1 = a%10;
        int b1 = b%10;
        a=a/10;
        b=b/10;
        long long c1 = (a1+b1)/10;
        c1 = c1 + a + b;
        int c2 = (a1 + b1)%10;
        if(c1>0) cout<<c1;
        cout<<c2;
        n--;
    }
}
