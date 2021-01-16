#include<bits/stdc++.h>
using namespace std;

int T; //So testcase
int n, m; // So luong phan tu cua hai mang;
int a[100000], b[100000];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >> T;
    while (T) {
        T--;
        int dem = 0;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> m;
        for (int i = 0; i < m; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dem += 1;
                    break;
                }
            }
        }
        cout << dem << endl;
    }
    return 0;
}
/* Test
1 4
2 1 4 3
3
1 5 4
*/