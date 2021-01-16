#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m, temp, res=0;
    cin>>t;
    set<int> a;
    set<int> b;
    while(t--){
        cin>>n;
        for (int i = 0; i<n; i++){
            cin>>temp;
            a.insert(temp);
        }
        cin>>m;
        for (int i = 0; i<m; i++){
            cin>>temp;
            if (a.find(temp)!=a.end()) res++;
        }
        cout<<res<<endl;
    }
}