#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
int id[MAX];
int d[MAX];
void initialize(){
    for(int i=2; i<=MAX; ++i){
        for(int j=i; j<=MAX; j+=i){
            id[j]+=1;
        }
    }
}
int main(){
    int n, t, k, s, res;
    cin>>s;
    for(int i=1; i<=MAX; ++i)   id[i]=1;
    initialize();
    for(int i=0; i<s; ++i){
    cin>>n;
    t=n*(n+1)*(n+2);
    k=t*t;
    res=id[k]-id[t];
    for(int i=t+1; i<k; ++i)    d[i]=0;
    for(int i=t+1; i<=k; ++i){
        for(int j=i; j<=k; j+=i){
            d[j]+=1;
        }
    }
    cout<<res-d[k];
    }
    return 0;
}
