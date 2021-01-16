#include<bits/stdc++.h>

int t, n;
int a[100001];
std::deque<int> aa;
int main() {
    std::cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        std::cin >> n;
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i];
            aa.push_back(a[i]);
        }
        int res = 0;
        while(aa.size() > 1) {
            int l = aa.size();
            int best = 0;
            while(l > 1) {
                int sum = aa.front();
                aa.pop_front();
                sum += aa.front();
                aa.pop_front();
                best = std::max(best, sum);
                aa.push_back(sum);
                l -= 2;
            } 
            if(l == 1) {
                aa.push_back(aa.front());
                aa.pop_front();
            }
            res += best;
        }
        std::cout << res;
    }
    return 0;
}