#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10004
// int s[MAX_N];
unsigned long long A[MAX_N][MAX_N];
int n[11];

int beauSeq(int k, unsigned long long B[MAX_N][MAX_N]){
    int s[MAX_N];
    s[1]=1;
    int res=s[1];
    for(int i=2;i<=n[k];i++){
        s[i]=1;
        for(int j=1;j<=n[k]-1;j++){
            if((B[k][i]-B[k][j])==1){
                if(s[i]<s[j]+1){
                    s[i]=s[j]+1;
                }
            }
        }
        if(s[i]>res) res=s[i];
    }
    return res;
}
int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n[i];
        // unsigned long long a[MAX_N];
        for(int j=1;j<=n[i];j++){
            cin>>A[i][j];
            // A[i].push_back(a[j]);
        }
    }
    for(int i=1;i<=T;i++){
       cout<<beauSeq(i,A);
    }
    
}