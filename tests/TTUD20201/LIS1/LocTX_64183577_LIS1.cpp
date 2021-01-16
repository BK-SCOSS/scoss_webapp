#include<bits/stdc++.h>
using namespace std;

int lis1(int i, const vector<int>& a, vector<int>& dp) {
    if(dp[i] != -1) {
        return dp[i];
    }

    int maxL = 1;
    for(int j = 0; j < i; j++) {
        if(a[j]+1 == a[i]) {
            maxL = max(maxL, lis1(j, a, dp)+1);
        }
    }

    dp[i] = maxL;
    return maxL;
}

void solve() {
    int N;
    cin >> N;
    vector<int> a;
    for(int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    vector<int> dp(N, -1);
    int res = 1;
    for(int i = 1; i < N; i++) {
        if(res < lis1(i, a, dp)) {
            res = lis1(i, a, dp);
        }
    }

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
