#include <bits/stdc++.h>

using namespace std;
int T, n;
int a[100100];
int main()
{
//    #ifndef ONliNE_JUDGE
//    freopen("D:\\input\\3.txt","r",stdin);
//    #endif // ONliNE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i<=n; i++) cin >> a[i];
        int res = 0, Size = n;
        while (Size != 1) {
            int _max = -1, i;
            for (i = 1; i<=Size/2;i++) {
                a[i] = a[2*i-1] + a[2*i];
                _max = max(_max,a[i]);
            }
            if (Size %2) a[i] = a[Size];
            res+= _max;
            Size = (Size+1)/2;
        }
        cout << res << endl;
    }

    return 0;
}
