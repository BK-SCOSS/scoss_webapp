#include<bits/stdc++.h>
using namespace std;
int a[100000];
vector<int> m(100000,1);

void list1(int u){
    for(int i=0;i<u;i++){
        if(a[u]==a[i]+1){
            if(m[u]<m[i]+1) m[u]=m[i]+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        int Max=0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin>> a[i];
        }
        for(int i=0;i<n;i++){
            list1(i);
        }
        for(int i=0;i<n;i++){
                //cout<<m[i]<<" ";
            if(Max<m[i]){
                Max = m[i];
            }
        }
        cout<<Max<<endl;
    }
    return 0;
}
