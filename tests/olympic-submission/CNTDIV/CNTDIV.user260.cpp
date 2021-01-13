#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define w(var) cerr << "DEBUG: " << (#var) << " = " << (var) << ";" << endl
#else
#define w(var)
#endif

int n, k;

tuple <int, int64_t, int64_t> user[1000006];

vector <int64_t> values;

int64_t dp[1000006];

int64_t fwtree[2000006];

unordered_map <int64_t, int> mpos;

int64_t get(int node) {
    int64_t res = 0;
    for (; node; node -= node & -node) {
        res = max(res, fwtree[node]);
    }
    return res;
}

void upd(int node, int64_t val) {
    for (; node <= 2000000; node += node & -node) {
        fwtree[node] = max(fwtree[node], val);
        // w(node);
        // w(fwtree[node]);
    }
}

void minimal() {
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());
    int cnt = 0;
    for (int64_t s: values) {
        mpos[s] = ++cnt;
    }
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> get<0>(user[i]) >> get<1>(user[i]) >> get<2>(user[i]);
        get<1>(user[i]) = get<0>(user[i]) + get<1>(user[i]) + k - 1;
        values.push_back(get<0>(user[i]));
        values.push_back(get<1>(user[i]));
    }
    sort(user, user + n, [](tuple <int, int64_t, int64_t> u1, tuple <int, int64_t, int64_t> u2){
        if (get<0>(u1) < get<0>(u2)) return true;
        if (get<0>(u1) > get<0>(u2)) return false;
        if (get<1>(u1) < get<1>(u2)) return true;
        if (get<1>(u1) > get<1>(u2)) return false;
        if (get<2>(u1) < get<2>(u2)) return true;
        return false;
    });

    minimal();

    for (int i = 0; i < n; ++i) {
        dp[i] = dp[i] + get(mpos[get<0>(user[i])] - 1) + get<2>(user[i]);
        upd(mpos[get<1>(user[i])], dp[i]);
    }

    for (int i = 0; i < n; ++i) {
        w(dp[i]);
    }
    cout << *max_element(dp, dp + n);
}