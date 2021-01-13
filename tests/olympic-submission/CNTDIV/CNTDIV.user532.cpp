#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long a[1000000];
unsigned long long b[1000000];
unsigned long long t;
void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        t= a[1]*(a[1]+1)*(a[1]+2);
        b[i]=0;
        unsigned long long l = t*t;
        for(int j=1;j<t;j++){
            if(l % j==0 && t % j!=0) b[i]++;
        }
    }
}
void output(){
    for(int i=1;i<=n;i++) cout<<b[i]<<endl;
}
int main() {
    input();
    solve();
    output();
}
