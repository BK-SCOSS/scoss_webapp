#include <bits/stdc++.h>

#define N 1000005
#define B (1LL << 32)
using namespace std;

int n, k;
int s[N], d[N], r[N], p[N];
unordered_map<long long, long long> bit;

long long get_bit(long long i) {
    if (i <= 0) {
        return 0;
    }
    long long w = 0;
    for (; i; i -= i & (-i)) {
        if (bit.count(i)) {
            w = max(w, bit[i]);
        }
    }
    return w;
}

void update_bit(long long i, long long w) {
    for (; i < B; i += i & (-i)) {
        if (!bit.count(i)) {
            bit[i] = w;
        } else {
            bit[i] = max(bit[i], w);
        }
    }
}

bool cmp(int i, int j) {
    return s[i] < s[j];
}

int randint(int l, int r) {
    return 1LL * rand() * rand() % (r - l + 1) + l;
}

void gen_test(char* input_file, int n, int k, int s, int d, int r) {
    ofstream fi(input_file);
    fi << n << " " << randint(1, k) << "\n";
    for (int i = 0; i < n; i++) {
        fi << randint(1, s) << " " << randint(1, d) << " " << randint(1, r) << "\n"; 
    }
    fi.close();
}

int main() {
    // srand(time(NULL));
    // char inf[] =  "01.inp";
    // char outf[] = "01.ans";
    // gen_test(inf, 50, 5, 10000, 1000, 1000);
    // freopen(inf, "r", stdin);
    // freopen(outf, "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> d[i] >> r[i];
        p[i] = i;
    }
    sort(p, p + n, cmp);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int j = p[i];
        long long w = get_bit(s[j] - k - 1);
        update_bit(s[j] + d[j] - 1, w + r[j]);
        ans = max(ans, w + r[j]);
    }
    cout << ans;
    // fclose(stdin);
    // fclose(stdout);
}