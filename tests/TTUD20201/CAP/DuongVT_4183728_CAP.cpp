#include<bits/stdc++.h>
using namespace std;
#define MAX 102
// typedef unsigned long long  ull;
int main(){
    int T;
    cin>>T;
    int cnt;
    for(int i=1;i<=T;i++){
        cnt=0;
        int n,m;
        unsigned long long a[MAX],b[MAX];
        stack<unsigned long long> s;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]==b[j]) cnt++;
            }
        }
        cout<<cnt;
    }
}