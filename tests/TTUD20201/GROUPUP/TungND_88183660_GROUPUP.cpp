#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void inputData();
void getAns();
void Try(int k);

int T, n;
vector<int> a;
vector<int> b;
int ans;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		inputData();
		Try(1);
	}
	return 0;
}

void inputData() {
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
}

void getAns() {
	int sum = 0;
	for (int i = 0; i < b.size(); i++) {
		sum += b[i];
	}
	cout << sum << endl;
}

void Try(int k) {

	if (n == 0) {
		getAns();
		return;
	}
	else {
		int t = 0, j = 0;
		if (n % 2) {
			for (int i = 0; i <= n - 2; i += 2) {
				a[j] = a[i] + a[i + 1];
				t = max(t, a[j]);
				j++;
			}
			b.push_back(t);
			n /= 2;
			a.resize(n);
			Try(k + 1);
		}
		else {
			for (int i = 0; i <= n - 1; i += 2) {
				a[j] = a[i] + a[i + 1];
				t = max(t, a[j]);
				j++;
			}
			b.push_back(t);
			n /= 2;
			a.resize(n);
			Try(k + 1);
		}
	}
}