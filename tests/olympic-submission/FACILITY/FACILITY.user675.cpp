#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 123;
struct customer {
    int start = 0;
    LL end = 0;
    int cost = 0;

    bool operator < (const customer &oth) {
        if (end < oth.end)
            return 1;
        if (end == oth.end && start  > oth.start)
            return 1;
        return 0;
    }
}customers[N];

LL dp[N];

int main() {

    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1 ; i <= n ; ++ i) {
        int s,d,c;
        scanf("%d%d%d",&s,&d,&c);
        customers[i].start= s;
        customers[i].end = 1LL*s + d + k - 1;
        customers[i].cost = c;
    }
    sort(customers+1,customers+n+1);
    vector < LL > s;
    for (int i = 1 ; i <= n ; ++ i) {
        dp[i] = dp[i-1];
        s.push_back(customers[i].end);
        int pos = lower_bound(s.begin(), s.end(), customers[i].start) - s.begin();
        dp[i] = max(dp[i], dp[pos] + customers[i].cost);
    }

    printf("%lld",dp[n]);
    return 0;
}
