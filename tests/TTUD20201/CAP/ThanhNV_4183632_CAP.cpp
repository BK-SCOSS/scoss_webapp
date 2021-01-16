#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int t,n,m;
int a[MAX];
int b[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;

    while(t--){
        int cnt=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i]==b[j]) cnt++;
            }
        }
    cout<<cnt<<endl;
    }
    return 0;
}
