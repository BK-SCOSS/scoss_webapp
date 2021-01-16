#include<bits/stdc++.h>

using namespace std;


unsigned int t,n,m,bien;
set<unsigned int> a,b,v;
unsigned int ans[10];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(unsigned int i=0;i<t;i++){
        cin>>n;
        for(int h =0;h<n;h++){
            cin>>bien;
            a.insert(bien);
        }
        cin>>m;
        for(int h=0;h<m;h++){
            cin>>bien;
            b.insert(bien);
        }
        set_intersection(a.begin(),a.end(),b.begin(),b.end(),std:: inserter(v,v.begin()));
        ans[i]=v.size();
        a.clear();
        b.clear();
        v.clear();
    }
    for(unsigned int i=0;i<t;i++) cout<<ans[i]<<endl;

}
