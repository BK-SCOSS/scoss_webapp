#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int n;
int a[MAX];
int best[MAX];


int liss(int i) {
    if(best[i]!= -1) return best[i];

    int res = 1;
    for(int j = 0; j<i; j++) {
        if(a[j] == a[i]-1) res = max(res, 1 + liss(j));
    }
    best[i] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, maxx = 0;
    cin >> t;
    while(t--) {
        memset(best, -1, MAX);
        cin >> n;
        for(int i = 0; i<n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i<n; i++) {
            best[i] = liss(i);
            maxx = max(maxx, best[i]);
        }
        cout << maxx << endl;
    }
}
