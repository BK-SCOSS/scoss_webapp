#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int *mem;
int *a;

int longest(int k)
{
    if (k == 0) return 1;
    if (mem[k] > 0) return mem[k];

    int res = 1;
    for (int i=k-1; i>=0; i--) {
        if (a[i] + 1 == a[k]) {
            mem[i] = longest(i);
            res = max(res, mem[i] + 1);
            break;
        }
    }
    mem[k] = res;
    return res;
}

int main()
{
    int t;
    cin >> t;
    int res = 0;

    while (t--) {
        res = 0;
        cin >> n;
        a = new int[n];
        mem = new int[n];

        for (int i=0; i<n; i++) {
            mem[i] = 0;
            cin >> a[i];
        }

        for (int i=0; i<n; i++) {
            mem[i] = longest(i);
            res = max(res, mem[i]);
        }

        cout << res << endl;

        delete []a;
        delete []mem;
    }
}
