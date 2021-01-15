#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 6;
long long divisor[MAX + 10];
map<int, int> prime;

void fact(int n) {
    while(n != 1) {
        int d = divisor[n];
        while(n % d == 0) {
            prime[d] ++;
            n /= d;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    for(int i = 2; i <= MAX ; i ++) {
        if(divisor[i]) continue;
        divisor[i] = i;
        for(long long j = 1LL * i * i; j <= MAX; j += i) divisor[j] = i;
    }
    int test;
    cin >> test;
    while(test --) {
        long long n;
        cin >> n;
        prime.clear();
        fact(n);
        fact(n + 1);
        fact(n + 2);
        long long res1 = 1, res2 = 1;
        for(auto tmp : prime) {
            int q = tmp.second;
            res1 = res1 * (q + 1);
            res2 = res2 * (2 * q + 1);
        }
        cout << (res2 + 1) / 2 - res1 << '\n';
    }
}