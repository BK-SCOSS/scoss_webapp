#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
int T;
int n,m;
int a[MAX],b[MAX];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cin >> m;
        for(int j=0;j<m;j++){
            cin >> b[j];
        }
        set<int>Y;
        for(int i=0;i<n;i++){
            Y.insert(a[i]);
        }
        for(int j=0;j<m;j++){
            Y.insert(b[j]);
        }
        //for(auto it =Y.begin();it!=Y.end();it++){
            //cout << *it <<endl;
        //}
        //cout << Y.size()<<endl;
        int ans =n+m-Y.size();
        cout << ans ;
    }
}
