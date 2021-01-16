#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        int num;
        int maxTime;
        int sum = 0;
        cin >> n;

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            q.push(num);
        }

        while(q.size() != 1) {
            maxTime = -1;
            int step = q.size() / 2;
            int sizeQ = q.size();
            while(step--) {
                int a = q.front();
                q.pop();
                int b = q.front();
                q.pop();
                maxTime = max(maxTime, a + b);
                q.push(a + b);
            }
            if (sizeQ % 2 == 1) {
                int a = q.front();
                q.pop();
                q.push(a);
            }
            sum += maxTime;
        }
        cout << sum << endl;
    }
    return 0;
}
