#include<bits/stdc++.h>
#define MAX 105
using namespace std;


int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        int a[MAX];
        int b[MAX];
        set<int> s;
     //   int cnt=0;
        int cnt1=0;
        int cnt2=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s.insert(a[i]);
            cnt1++;
        }
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>b[j];
            s.insert(b[j]);
            cnt2++;
        }
    //   for(set<int>::iterator it=s.begin();it!=s.end();it++){
    //      cnt++;
    //   }
        cout<<cnt1+cnt2-s.size();
    }
    return 0;
}
