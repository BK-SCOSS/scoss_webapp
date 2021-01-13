#include <bits/stdc++.h>
using namespace std;
int t;
unsigned long long a, b;
int add(unsigned long long a, unsigned long long b){
    int a1 = a % 10;
    a /= 10;
    int b1 = b % 10;
    b /= 10;

    a1 += b1;
    b1 = a1 /10;
    a1 = a1 % 10;

    a += b + b1;
    if(a != 0) cout<<a;
    cout<<a1<<'\n';
}
int main(){
    //freopen("test.inp","r",stdin);
    cin>>t;
    while(t){
        t--;
        cin>>a>>b;
        add(a, b);
    }
}
