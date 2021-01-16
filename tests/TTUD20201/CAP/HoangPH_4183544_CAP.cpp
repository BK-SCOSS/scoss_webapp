#include<bits/stdc++.h>
using namespace std;
#define MAX 105
int t;
int n,m;
int a[MAX],b[MAX];

int main(){
    cin>>t;
    while(t--){
        int count1=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        for(int i=1;i<=n-1;i++){
            if(a[i]==a[i+1]) a[i]=0;
        }
        for(int j=1;j<m;j++){
            if(b[j]==b[j+1]) b[j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]!=0&&(a[i]==b[j])){
                    count1++;
                }
            }
        }
        cout<<count1<<endl;
    }
}