#include <bits/stdc++.h>
using namespace std;
vector<int> dp(100001, 0);
int T;
int n;
int *arr;
int global_max = 1;

void max_sub()
{
    unordered_map<int, int> hM;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        dp[i] = max(dp[i], hM[arr[i] - 1] + 1);
        hM[arr[i]] = dp[i];
        global_max = max(dp[i], global_max);
    }
}
void solve()
{

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        max_sub();
        cout << global_max << endl;
        global_max = 1;
    }
}
int main()
{
    solve();
}