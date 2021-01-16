#include <bits/stdc++.h>

using namespace std;
const int oo = -1e9;
int T, n, a[100100], L[100100];
int main()
{
    //freopen("D:\\input\\2.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    map<int,int> F;
    while (T--) {
        cin >> n;
        int res = oo;
        for (int i = 1; i <=n; i++) {
            cin >> a[i];
            L[i] = 1;
            F[a[i]] = i;
            if (F.find(a[i]-1) != F.end()) {
                L[i] = max(L[i],L[F.at(a[i]-1)]+1);
            }
            res = max(res,L[i]);
        }
        cout << res << endl;
        F.clear();
    }
    return 0;
}
