#include<bits/stdc++.h>
using namespace std;

int const MAX = 1e6;
int T;
int n;
int a[MAX];
int S[MAX];
int ans;

int main(){
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    S[1] = 1;
    ans = S[1];
    for (int i = 2; i <= n; i++) {
        S[i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            if (a[i] == a[j] + 1) {
                if (S[i] < S[j] + 1)
                    S[i] = S[j] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, S[i]);

    cout << ans;
  }
}
