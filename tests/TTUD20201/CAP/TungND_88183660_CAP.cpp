#include<iostream>
#include<vector>
#include<map>
using namespace std;

void intputData();
void outputData();
void swap2(vector<int> &x, vector<int> &y);
int countElements(vector<int>x, vector<int>y);

int T,m, n;
vector<int>a, b;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		intputData();
		swap2(a, b);
		//outputData();
		cout << countElements(a, b) << endl;
	}
	return 0;
}

void intputData() {
	int x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> y;
		b.push_back(y);
	}
}

void outputData() {
	for (auto it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << endl;
	for (auto it = b.begin(); it != b.end(); it++)
		cout << *it << " ";
}

int countElements(vector<int>x, vector<int>y) {
	map<int, int>check;
	
	int countE = 0;
	for (auto it = x.begin(); it != x.end(); it++) {
		for (auto j = y.begin(); j != y.end(); j++) {
			if (check.count(*it) == 0) {
				if (*it == *j) {
					if (check.count(*j) == 0) {
						countE++;
						check.insert({ *j,1 });
					}
				}
			}
		}
	}

	return countE;
}

void swap2(vector<int> &x, vector<int> &y) {
	int i = x.size();
	int j = y.size();
	vector<int> tmp;
	if (i > j) {
		x.swap(y);
	}
}