#include<bits/stdc++.h>

int t, n;
uint64_t a[100001];
int res = 0;
int mem[100001] = {0};

int best(int pos) {
    if(pos == n) return 1;
    if(mem[pos] != 0) return mem[pos];
    int best_in = 0;
    for(int i = pos+1; i <=n; i++) {
        if(a[i] != a[pos]+1 ) continue;
        best_in = std::max(best_in, best(i));
        break;
    }
    mem[pos] = best_in + 1;
    return best_in + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        std::cin >> n;
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        res = 0;
        for(int i = 1; i <= n; i++) {
            if(n-i < res) continue;
            res = std::max(res, best(i));
        }
        std::cout << res;
    }
    return 0;
}