#include <bits/stdc++.h>
using namespace std;

int count_div (long long n) {
    int res =0;
    for (int i=1;i<sqrt(n);i++) {
        if (n%i==0) res ++;
    }
    if (round(sqrt(n))*round(sqrt(n)) == n) return 2*res+1;
    else return 2*res;
}

int main() {
    int n,a;
    long long t;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        t = a*(a+1)*(a+2);
        cout << (count_div(t*t)-1)/2 - (count_div(t)-1)  << endl;
    }
}
