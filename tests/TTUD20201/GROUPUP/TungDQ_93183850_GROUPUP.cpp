#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e6;
int n, ans;
int a[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++){
    cin >>n;
    for (int i = 1 ; i <= n; i++) {
            cin >> a[i];
    }
    ans = 0;
    while (n != 1) {
         int tmp = 0;
         int key = 0;
         if (n % 2 == 1) tmp = a[n];
         if (n != 1 && tmp != 0) key = 1;
         int cnt = 1;
         n = n/2;
         int i = 1;
         while (cnt <= n) {
         a[cnt] = a[i] + a[i+1];
         cnt++;
         i = i + 2;
    }
    if ( tmp != 0 ) {
            a[cnt] = tmp;
    }
    else cnt --;
    if (key) n++;
    int res = 0;
    for (int i = 1 ; i <= cnt; i++) {
            res = max (res, a[i]);
    }
    ans += res;
    }
     cout <<ans;
    }
    return 0;
}
