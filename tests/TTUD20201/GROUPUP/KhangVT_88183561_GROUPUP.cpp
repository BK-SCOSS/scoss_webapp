#include <iostream>
#include <vector>
#include <queue>
#define N 100003
using namespace std;

int t, n, a[N];
vector<int> v;

int main () {

    cin >> t;
    while (t--) {
        cin >> n;

        for ( int i = 0; i < n; ++i ) {
            cin >> a[i];
        }

        int rev = 0;
        while (n > 0) {
            if (n == 1) {
                rev *= 2;
                break;
            }
            priority_queue<int> q;
            v.clear();
            while(!q.empty()) q.pop();
            for ( int i = 0; i < n; i += 2) {
                a[i] = a[i] + a[i + 1];
                v.push_back(a[i]);
//                cout << a[i] << " ";
                q.push(a[i]);
            }
            rev += q.top();
            n /= 2;
            for ( int i = 0; i < n; ++i ) {
                a[i] = v[i];
            }
            for ( int i = n; i < n * 2; ++i) {
                a[i] = 0;
            }
        }

        for ( int i = 0; i < n; ++i ) {
            a[i] = 0;
        }
        v.clear();
        cout << rev << '\n';
    }
}