#include <bits/stdc++.h>

using namespace std;

int main() {
    int test, n;
    cin >> test;
    for (int t = 0; t < test; t++) {
        int res = 1, val;
        map<int, int> mem_map;
        cin >> n;
        int *arr = new int[n];
        int *mem = new int[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) mem[i] = 1;
        
        for (int i = 0; i < n; i++) {
            auto search = mem_map.find(arr[i] - 1);
            if (search != mem_map.end()) {
                val = mem_map[arr[i] - 1] + 1;
            } else {
                val = 1;
            }
            mem_map[arr[i]] = val;
            res = max(val, res);
        }

        cout << res << "\n";
    }
    return 0;   
}
