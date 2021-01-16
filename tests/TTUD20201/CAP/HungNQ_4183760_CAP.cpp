#include <bits/stdc++.h>
#define MAX 1000

using namespace std;


int main(){
    int T, n, m;
    int a[MAX], b[MAX];
    //freopen("CAP.inp", "r", stdin);
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);

        //for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
        //for (int i = 1; i <= m; i++) cout << b[i] << ' '; cout << endl;


        int cnt = 0;

        int i = 1, j = 1;
        while (i <= n && j <= m){
            if (a[i] == b[j]) { cnt ++; i++; j++;}
            else if (a[i] < b[j]) i++;
            else j++;
        }
        cout << cnt << '\n';
    }
}
