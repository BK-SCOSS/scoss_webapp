#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[105], b[105];


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int cnt = 0;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
					cnt++;
					//b[j] = 0;	    
                }
            }
        cout << cnt << endl;
    }
    return 0;
}
