#include <bits/stdc++.h>

using namespace std;

int main() {
    int test, n;
    cin >> test;
    for (int t = 0; t < test; t++) {
        cin >> n;
        int res = 0, sub_res;
        int *arr = new int[n];
        int *sub_arr = new int[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        while (n > 1) {
            if (n % 2 == 0) {
                for (int i = 0; i < n; i+=2) sub_arr[i / 2] = arr[i] + arr[i + 1];
                sub_res = sub_arr[0];
                for (int i = 0; i < n / 2; i++) sub_res = max(sub_res, sub_arr[i]);
                n /= 2;
             }
             else {
                sub_res = arr[0] + arr[1];
                for (int i = 0; i < n - 1; i+=2) {
                    sub_arr[i / 2] = arr[i] + arr[i + 1];
                    sub_res = max(sub_res, arr[i] + arr[i + 1]);
                }
                sub_arr[(n - 1) / 2] = arr[n - 1];
                n = (n + 1) / 2;
             }

             for (int i = 0; i < n; i++) arr[i] = sub_arr[i];
             res += sub_res;
        }
        cout << res << "\n";
    }
    return 0;   
}
