#include <bits/stdc++.h>

using namespace std;

string cong(string a, string b) {
  while (a.size() < b.size()) a = '0' + a;
  while (b.size() < a.size()) b = '0' + b;
  int nho = 0;
  string ans = "";
  for (int i = b.size() - 1; i >= 0; i--) {
    int s = b[i] + a[i] - 96 + nho;
    nho = 0;
    if (s > 9) {
      s %= 10;
      nho = 1;
    }
    ans += char(s + 48);
  }
  if (nho) ans += "1";
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b;
    cin >> a >> b;
    cout << cong(a, b) << "\n";
  }
}
