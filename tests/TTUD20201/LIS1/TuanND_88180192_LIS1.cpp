#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;

        vector<int> a(n+1), d(n+1, 1);
        map<int, int> current_max;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int res = 1;
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                current_max[a[i]] = 1;
                continue;
            }
            d[i] = current_max[a[i]-1] + 1;
            current_max[a[i]] = d[i];
            //cout << "d[" << i << "] = " << d[i] << endl;
            if(res < d[i]) res = d[i];
        }

        cout << res << endl;
    }
}


