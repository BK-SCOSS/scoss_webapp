#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int t;
int n;
int a[MAX];
int s[MAX];
int main(){
    cin>>t;
    while(t--){
        s[1]=1;
        int res=1;
        int k=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=2;i<=n;i++){
            s[i]=1;
        for(int j=1;j<=i-1;j++){
            if((a[j]+1)==a[i]){
                if(s[i]<s[j]+1){
                    s[i]=s[j]+1;
                }
            }
        }
        if(s[i]>res) res =s[i];
        }

    cout<<res;
    }
}