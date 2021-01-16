#include <iostream>

using namespace std;

long long T, n , a[100001], tong = 0;

int Try(long long x, long long a[]){
    if (x <= 1) return tong;
    int du = 0;
    long long b[100001];
    if (x%2 == 1){
        du = a[x];
        x = x-1;
    }
    int chay = 0;
    for (int i = 1; i<= x; i+=2){
        chay++;
        b[chay] = a[i] + a[i+1];
    }
    int mx = 0;
    for (int i=1; i <= chay ; i++){
        if (mx < b[i]) mx = b[i];
    }
    tong += mx;
    if (du != 0){
        chay++;
        b[chay] = du;
    }
    Try(chay, b);
}
int main() {
    cin >> T;
    while (T--){
        tong = 0;
        cin >> n;
        for (int i = 1; i<= n ; i++) cin >> a[i];
        Try(n,a);
        cout << tong << endl;
    }
    return 0;
}
