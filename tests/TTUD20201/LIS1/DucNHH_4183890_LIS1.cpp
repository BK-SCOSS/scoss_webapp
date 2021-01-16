#include <iostream>

using namespace std;

int main()
{
    int T, ans[11];
    cin >> T;
    for(int x = 0; x < T; x++) {
        int n, so = 1, best = 0;
        int a[100001], c[100001], b[100001];
        cin >> n;
        cin >> a[0];
        b[0] = a[0];
        c[0] = 1;
        for(int i = 1; i < n; i++) {
            cin >> a[i];
            int k = 0;
            for(int j = 0; j < so; j++) {
                if(a[i] == b[j] + 1) {
                    b[j] = a[i];
                    c[j]++;
                    break;
                }
                k++;
            }
            if(k == so) {
                b[so] = a[i];
                c[so] = 1;
                so++;
            }
        }
        for(int i = 0; i < so; i++) {
            best = max(best, c[i]);
        }
        ans[x] = best;
    }
    for(int i = 0; i < T; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
