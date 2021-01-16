#include <bits/stdc++.h>
using namespace std;

int t, n, result;
vector<int> a;
vector<int> tmp;
vector<int> time_;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n; 
		while (n--) {
			int x = 0;
			cin >> x;
			a.push_back(x);
		}
		while (a.size()>1) {
			int max_time = 0;
			for (int i = 0; i < (a.size() / 2); i++) {
				tmp.push_back(a[2*i] + a[2*i + 1]);
				max_time = max(max_time,a[2 * i] + a[2 * i + 1]);
			}
			if (a.size() % 2 == 1) {
				tmp.push_back(a[a.size() - 1]);
				max_time = max(max_time, a[a.size() - 1]);
			}
			time_.push_back(max_time);
			a.clear();
			for (int i = 0; i < tmp.size(); i++)
				a.push_back(tmp[i]);
			tmp.clear();
		}

		for (int i = 0; i < time_.size(); i++)
			result += time_[i];
		cout << result << endl;
	}
    return(0);
}