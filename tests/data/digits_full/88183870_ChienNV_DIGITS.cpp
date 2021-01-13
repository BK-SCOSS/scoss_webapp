#include <bits/stdc++.h>

using namespace std;
// HUS + SOIC = S*1001 + (H+O)*100 + (U+I) * 10 + C
bool check[9] = {false};
int a[8];
int res = 0;
bool check_res(int n) {
    if(a[2] * a[3] == 0)
        return false;
    if(a[1] * 2 + (a[2] * 1001 + (a[3] + a[4]) * 100 + (a[5] + a[6])* 10 + a[7])*10 == n) {
        return true;
    }
    return false;
}
void Try(int k, int n) {
    for(int i = 0; i <= 9; i++) {
        if(!check[i]) {
            a[k] = i;
            check[i] = true;
            if(k == 7) {
                if(check_res(n)) res++;
            } else Try(k+1, n);
            check[i] = false;
        }
    }
}
int digit(int n) {
    if(n % 2 == 1) {
        return 0;
    }
    Try(1, n);
    return res;
}

int main() {
    int n, Test;
    cin >> Test;
    while(Test--) {
        cin >> n;
        cout << digit(n) << endl;
        res = 0;
    }
    return 0;
}
