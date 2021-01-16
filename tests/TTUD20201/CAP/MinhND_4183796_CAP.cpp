#include<bits/stdc++.h>
using namespace std;
int n, m, t;




int main() {
    cin >> t;
    
    for( int l = 1; l <= t; l++) {
        int a[109], b[109], ans = 0;
        vector<int> u,v;

        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            
        }

        cin >> m;
        for(int i = 1; i <= m; i++) {
            cin >> b[i];
            
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i] == b[j]) ans++;
            }
        }
        cout << ans;
    }
}

