#include <bits/stdc++.h>

using namespace std;

int ans, sum;
vector<int> a;

void merge(vector<int> &a) {
    int s = a.size();
    vector<int> b;

    if (s <= 1) {
        ans = sum;
        return;
    } else if (s % 2 == 0) {
        b.resize(s / 2);
        int index = 0;
        for (int i = 0; i < s; i = i + 2) {
            b[index] = (a[i] + a[i+1]);
            index++;
        }
        sum += *max_element(b.begin(), b.end());
        a.clear();
        merge(b);
    } else if (s % 2 != 0) {
        b.resize(s / 2 + 1);
        int index = 0;
        for (int i = 0; i < s - 1; i = i + 2) {
            b[index] = (a[i] + a[i+1]);
            index++;
        }
        b[index] = a[s-1];
        sum += *max_element(b.begin(), b.end());
        a.clear();
        merge(b);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //  freopen("VD2/GROUPUP.inp", "r", stdin);
    //  freopen("test.out", "w", stdout);

    int T,n, tg;
    cin >> T;

    for (int z = 0; z < T; z++) {
        cin >> n;
        ans = 0;
        sum = 0;
        a.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        merge(a);

        cout << ans << endl;
    }

    return 0;
}