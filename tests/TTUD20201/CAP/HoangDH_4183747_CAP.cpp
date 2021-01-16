#include<bits/stdc++.h>
using namespace std;

#define MAX 150
int T; // so test case
int n, m; // so phan tu cua 2 day
unsigned long long a[MAX], b[MAX]; // 2 day

int main(){
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            if (a[i]==a[j]) a[j] = -1;
        }

    }

    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m - 1; j++) {
            if (b[i]==b[j]) b[j] = -1;
        }

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ( (a[i] == b[j]) && (a[i] != -1) ) cnt++;
        }
    }

  cout << cnt << endl;
}
  return 0;
}
