#include <bits/stdc++.h>
using namespace std;

int maxPing = 1, maxArr = 1;

int handle_me(int k, int n, long long arr[]) {
  // if (k == n - 1) {
  //   maxArr = max(maxArr, maxPing);
    // cout << maxArr;
  //}
  for (int i = k + 1; i < n; i++) {
    if (arr[i] <= arr[k]) {
      continue;
    }
    if (arr[i] - arr[k] == 1) {
      maxPing++;
      handle_me(i, n, arr);
      maxPing--;
    }
  }
  maxArr = max(maxArr, maxPing);
  return maxArr;
}

int main() {
  int testCase;
  cin >> testCase;
  while (testCase--) {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int maxKiller = 0;
    // cout << handle_me(0, n, arr);
    for (int i = 0; i < n - 1; i++) {
      maxKiller = max(maxKiller, handle_me(i, n, arr));
    }
    cout << maxKiller;
  }

  return 0;


}
