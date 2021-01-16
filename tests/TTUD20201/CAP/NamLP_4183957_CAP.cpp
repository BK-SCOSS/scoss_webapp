#include <bits/stdc++.h>

using namespace std;
int t, n, m;
vector<int> a;
vector<int> b;
int ans;
int x;
int main() {
    cin >> t;
    while(t--){
        ans = 0;
        a.clear();
        b.clear();

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            a.push_back(x);
        }

        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> x;
            b.push_back(x);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int i = 0 ; i < m; i++){
            if(a[0] == b[i]) {
                ans = 1;
                break;
            }
        }

        for(int i = 1; i < n; i++){
            if(a[i] != a[i-1]){
                for(int j = 0; j < m; j++){
                    if(a[i] == b[j]) {
                        ans += 1;
                        break;
                    }
                }
            }
        }

        cout << ans << endl;

    }
}
