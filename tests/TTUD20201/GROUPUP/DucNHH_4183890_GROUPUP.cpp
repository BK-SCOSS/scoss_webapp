#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, ans[11];
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, a;
        ans[t] = 0;
        cin >> n;
        queue<int> q;
        int b[100001];
        for(int i = 0; i < n; i++) {
            cin >> a;
            q.push(a);
        }
        while(n != 1) {
            int x, y, k = 0;
            int m = n;
            while(m > 0) {
                int x = q.front();
                q.pop();
                m--;
                int y;
                if(!m) y = 0;
                else {
                    y = q.front();
                    q.pop();
                    m--;
                }
                b[k] = x+y;
                q.push(b[k]);
                k++;
            }
            int max = 0;
            for(int i = 0; i < k; i++) {
                max = max > b[i] ? max : b[i];
            }
            ans[t] += max;
            if(n % 2 == 0) n = n / 2;
            else n = n / 2 + 1;
        }
    }
    for(int i = 0; i < T; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
