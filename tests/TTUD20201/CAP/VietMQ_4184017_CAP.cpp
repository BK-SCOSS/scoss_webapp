#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 101;
int marked[MAX_N];

int main() {

    int T, n, m;
    cin >> T;
    while(T--) {
        int cnt = 0;
        vector<int> a;
        vector<int> b;

        cin >> n;
        for(int i = 0; i < n; i++) {
            int t = 0;
            cin >> t;
            a.push_back(t);
            marked[a[i]] = 0;
        }

        cin >> m;
        for(int i = 0; i < m; i++) {
            int t = 0;
            cin >> t;
            b.push_back(t);
            marked[b[i]] = 0;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i] == b[j]) {
                    if(!marked[a[i]]) {
                        cnt++;
                        marked[a[i]] = 1;
                    }
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
