#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define w(var) cerr << "DEBUG: " << (#var) << " = " << (var) << ";" << endl
#else
#define w(var)
#endif

struct order_t {
    int s, d, v;
};

int n, k;

int64_t ans = 0;

order_t order[1000006];

int values[2000006], nvalues;

int64_t fwtree[2000006];

int64_t get(int node) {
    int64_t res = 0;
    for (; node; node -= node & -node) {
        res = max(res, fwtree[node]);
    }
    return res;
}

void update(int node, int64_t val) {
    for (; node <= 2000000; node += node & -node) {
        fwtree[node] = max(fwtree[node], val);
        // w(node);
        // w(fwtree[node]);
    }
}

void minimal() {
    sort(values, values + nvalues);
    // nvalues = unique(values, values + nvalues) - values;
    int cnt = 0;
    for (int64_t i = 0 ; i < n; ++i) {
        order[i].s = lower_bound(values, values + nvalues, order[i].s) - values + 1;
        order[i].d = lower_bound(values, values + nvalues, order[i].d) - values + 1;
    }
}

int main () {
    // ios_base::sync_with_stdio(0);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &order[i].s, &order[i].d, &order[i].v);
        order[i].d = order[i].s + order[i].d + k - 1;
        values[nvalues++] = order[i].s;
        values[nvalues++] = order[i].d;
    }

    minimal();

    sort(order, order + n, [](const order_t &u1, const order_t &u2){
        return u1.s < u2.s || (u1.s == u2.s && u1.d < u2.d);
    });

    for (int i = 0; i < n; ++i) {
        int64_t res = get(order[i].s - 1) + order[i].v;
        update(order[i].d, res);
        ans = max(ans, res);
        w(res);
    }

    printf("%lld", ans);
}