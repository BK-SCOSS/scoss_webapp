#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int T;
int a[MAX], b[MAX];
int m,n;
int main(){
    cin >> T;
    while (T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >>a[i];
        }
        cin >> m;
        for(int j=0; j<m; j++){
            cin >> b[j];
        }
        set<int> Y;
        for (int i=0; i<n; i++){
            Y.insert(a[i]);
        }
        for(int j=0; j<m; j++){
            Y.insert(b[j]);
        }
        int ans=m+n-Y.size();
        cout << ans;
    }
}
