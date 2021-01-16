#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000000


void solve() {
    int N, M;
    cin >> N;
    set<int> a;
    for(int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }
    cin >> M;
    set<int> b;
    for(int i = 0; i < M; i++) {
        int bi;
        cin >> bi;
        b.insert(bi);
    }

    int ans = 0;
    for(set<int>::iterator it1 = a.begin(); it1 != a.end(); it1++) {
        for(set<int>::iterator it2 = b.begin(); it2 != b.end(); it2++) {
            if(*it1 == *it2) {
                ans++;
            }
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}
