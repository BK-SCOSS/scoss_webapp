#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int T, n, m;
int a[N], b[N];
int ans;


main(){
    cin >> T;
   
    for(int v=1; v<=T; v++){
    
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> a[j];
        }
        ans = 0;
        cin >> m;
        for(int i=0; i<m; i++){
            int x;
            cin >> x;
            for(int j=0; j<n; j++){
                if(x == a[j]){
                    ans++;
                    break;
                }
            }
            
        }
        cout << ans << endl;
    }
}