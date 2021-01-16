#include<bits/stdc++.h>
using namespace std;

int a[100005] = {},g[100005];
int n,res=0,t,temp;

map <int, int> arr;


void xuli() {
    for (int i = 0; i < n; i++) {
        arr[a[i]] = 1;
        auto search = arr.find(a[i] - 1);
        if (search != arr.end()) {
            arr[a[i]] = search->second + 1;

        }
        res = max(res, arr[a[i]]);

    }
}


int main() {
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int bestj = 0;
        xuli();
        cout << res << endl;
    }
}
