#include <bits/stdc++.h>

using namespace std;




int main(){
    int T;
    cin >> T;
    for (int i=1; i<=T; i++){
        int a[100];
        long n;
        cin >> n;

        for (int j=0;j<n;j++){
            cin >> a[j];
        }

        int ans = 0;
        long b,m;
        cin >> m;
        for (int j=0; j<m;j++){
            cin >> b;
            for (int k =0; k<n;k++){
                if (a[k]==b) {
                    ans++;
                    break;
                }
            }

        }
        cout << ans;
    }

}
