#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
int s[N];
int ans;
int main() {
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        s[1] = 1;
        ans = 1;
        for(int i = 2; i <= n; i++){
            s[i] = 1;
            for(int j = i-1; j > 0; j--){
                if(a[i] == (a[j]+1)){
                    s[i] = s[j]+1;
                    break;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            ans = max(ans, s[i]);
        }

        cout << ans << endl;
    }
}
