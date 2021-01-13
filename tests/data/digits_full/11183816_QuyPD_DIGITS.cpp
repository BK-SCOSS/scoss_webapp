#include <bits/stdc++.h>

using namespace std;

int n;
int a[8];
int x[10];
vector<int> v;
int ans;

void solution() {
    int sum = 1000*a[1] + 100*a[2] + 10*a[3] + a[4]
    + 10000*a[3] + 1000*a[5] + 100*a[6] + 10*a[7] + a[4];
    //cout << sum << endl;
    if (sum == n) {
        ++ans;
        //cout << a[1] << a[2] << a[3] << a[4] << "+" << a[3] << a[5] << a[6] << a[7] << a[4] << endl;
    }
}

bool check(int k, int i) {
    if (k == 1 || k == 3) {
        if (i == 0) return 0;
        if (x[i] == 1) return 0;
    }
    else {
        if (x[i] == 1) return 0;
    }
    return 1;
}

void Try(int k) {
    for (int i = 0; i < 10; ++i) {
        if (check(k, i)) {
            //cout << i << endl;
            a[k] = i;
            x[i] = 1;
            if (k == 7) solution();
            else Try(k+1);
            x[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        memset(x, 0, 10);
        Try(1);
        v.push_back(ans);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    return 0;
}
