#include <bits/stdc++.h>

using namespace std;
int test;
int n,m;
const int MAX = 102;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> test;
    while(test--) {
        long long a[MAX];
        long long b[MAX];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0 ; i < m ; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b,b+m);
        int res = 0;
        int tmp =0;
        for (int i = 0; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if(a[i] == b[j] && b[j] > tmp ) {
                    res++;
                    tmp = b[j];
                    break;
                }
            }
        }
        cout << res << endl;
    }
}