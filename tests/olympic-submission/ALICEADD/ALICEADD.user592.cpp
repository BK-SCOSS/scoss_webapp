#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 10;

string add(string a, string b) {
	while (a.length() < b.length()) a = '0' + a;
	while (b.length() < a.length()) b = '0' + b;
	string ans = "";
	int tmp = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		int sum = (a[i] - '0') + (b[i] - '0') + tmp;
		tmp = sum / 10;		
		char c = (sum % 10) + '0';
		ans = c + ans;
	}
	if (tmp == 1) ans = '1' + ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) {
		string a, b; cin >> a >> b;
		cout << add(a, b) << '\n';
	}
	
	return 0;
}