#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;
int T, n;
int a[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("LISS1.inp", "r", stdin);
    cin >> T;
    int result[T];
    for (int t = 0; t < T; t++){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        map<int, int> s;
        s[a[1]] = 1;

        set<int> B;
        B.insert(a[1]);

        for (int i = 2; i <= n; i++){
            auto x = B.find(a[i] - 1);
            if (x == B.end()) s[a[i]] = 1;
            else {
                int y = *x;
                s[a[i]] = s[y] + 1;
            }
            B.insert(a[i]);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) res = max (res, s[a[i]]);
        result[t] = res;
    }
    for (int t = 0; t < T; t++) cout << result[t] << '\n';
}
