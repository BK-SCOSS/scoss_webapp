#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, MAX = 1e9 + 1;
    int c[11];
    cin >> T;
    for(int x = 0; x < T; x++){
        int n, m, count = 0;
        int a[101], b[101];
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        int ca = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == a[i+1]){
                ca++;
                a[i] = MAX;
            }
        }
        sort(a, a+n);
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b, b+m);
        int cb = 0;
        for(int i = 0; i < m; i++) {
            if(b[i] == b[i+1]){
                cb++;
                b[i] = MAX;
            }
        }
        sort(b, b+m);
        for(int i = 0, j = 0; i < n-ca && j < m-cb;) {
            if(a[i] > b[j]) j++;
            else if(a[i] < b[j]) i++;
            else {
                count++;
                i++;
                j++;
            }
        }
        c[x] = count;
    }
    for(int i = 0; i < T; i++) {
        cout << c[i] << endl;
    }
    return 0;
}
