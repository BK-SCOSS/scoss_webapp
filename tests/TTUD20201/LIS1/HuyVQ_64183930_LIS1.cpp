#include<bits/stdc++.h>
using namespace std;

int T; //So testcase
int n;
int a[100001];
int mem[100001];

int calculate(int x) {
    if (x == 0) {
        mem[x] = 1;
        return mem[x];
    }
    else if (mem[x] != 0) return mem[x];
    else {
        int res = 1;
        for (int i = 0; i < x; i++) {
            int s = calculate(i);
            if (a[i] + 1 == a[x]) res = max(res, 1 + s);
        }
        mem[x] = res;
        return mem[x];
    }
}

int main () {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> T;
    while(T > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int maximum = 0;
        calculate(n-1);
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, mem[i]);
        }
        cout << maximum <<endl;
        T--;
    }
    return 0;
}