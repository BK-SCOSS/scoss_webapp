#include <bits/stdc++.h>
using namespace std;
const int MAX= 1000000;
long long n,k;
long long s[MAX],d[MAX],r[MAX],l[MAX],maxt=0;
void input(){
   cin>>n>>k;
   for(int i=1;i<=n;i++) {
       cin>>s[i]>>d[i]>>r[i];
       d[i]=s[i]+d[i]+k;
   }
}
void process(){
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(d[i]>d[j]){
                swap(d[i],d[j]);
                swap(s[i],s[j]);
                swap(r[i],r[j]);
            }
        }
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        l[i]=r[i];
        for(int j=1;j<=i-1;j++){
            if(d[j]<=s[i] && l[i] <l[j]+r[i]) {
                l[i]=l[j]+r[i];
            }
        }
        maxt=max(l[i],maxt);
    }
}
int main(){
   input();
   process();
   solve();
   cout<<maxt;
}