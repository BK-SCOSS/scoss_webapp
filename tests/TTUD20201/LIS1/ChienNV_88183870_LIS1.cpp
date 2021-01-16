#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int main(){
    int test;
    cin >> test;
    while(test--) {
        int n;
        int f[MAX];
        long long finish[MAX];
        long long a[MAX];
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = 1;
            finish[i] = a[i];
        }

        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                if(a[i] - finish[j] == 1) {
                    f[i] = f[j] + 1;
                }
            }
        }

        cout << *max_element(f+1, f+n+1) << endl;;

    }
    return 0;
}
