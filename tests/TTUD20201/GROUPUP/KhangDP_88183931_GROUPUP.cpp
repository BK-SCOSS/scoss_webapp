#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

void init() {
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        q.push(tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    int a, b;
    int MAX = 0;
    int result[11];
    for (int i = 0; i < 11; i++) {
        result[i] = 0;
    }
    cin >> T;
    for (int k = 0; k < T; k++) {
        init();
        while (n != 1) {
            if (n % 2 == 0) {
                for (int i = 0; i < n/2; i++) {
                    a = q.front();
                    q.pop();
                    b = q.front();
                    q.pop();
                    MAX = max(MAX, a + b);
                    q.push(a + b);
                }
            } else {
                for (int i = 0; i < n/2; i++) {
                    a = q.front();
                    q.pop();
                    b = q.front();
                    q.pop();
                    MAX = max(MAX, a + b);
                    q.push(a + b);
                }
                a = q.front();
                q.pop();
                q.push(a);
            }
            result[k] += MAX;
            MAX = 0;
            n = (int)q.size();
        }
        q.pop();
    }
    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
