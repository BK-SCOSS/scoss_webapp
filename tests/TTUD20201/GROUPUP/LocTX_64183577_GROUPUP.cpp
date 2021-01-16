#include<bits/stdc++.h>
using namespace std;

void recur(int& res, vector<int> a) {
    int n = a.size();
    if(n == 1)
        return;

    vector<int> new_a;
    int maxT = 0;
    for(int i = 0; i < n; i+=2) {
        int group = (i < n-1) ? (a[i] + a[i+1]) : a[i];
        new_a.push_back(group);
        maxT = max(maxT, group);
    }

    res += maxT;
    recur(res, new_a);
}

void solve() {
    int N;
    vector<int> a;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    int res = 0;
    recur(res, a);

    cout << res << endl;
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
