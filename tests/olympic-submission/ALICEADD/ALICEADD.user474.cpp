#include <iostream>
#include <string>
using namespace std;

string sum(string a, string b) {
	int i = a.size() - 1,j = b.size() - 1, m = 0, n = 0;
	string s;
	while (i >= 0 && j >= 0) {
		m = a[i] + b[j] - 48 * 2 + n;
		s = (char) (m % 10 + 48) + s;
		n = m / 10;
		j--; i--;
	}
	if (i <= 0) {
		while (j >= 0) {
			m = b[j] - 48 + n;
			s = (char)(m % 10 + 48) + s;
			n = m / 10;
			j--;
		}
	}
	else {
		while (i >= 0) {
			m = b[i] - 48 + n;
			s = (char)(m % 10 + 48) + s;
			n = m / 10;
			i--;
		}
	}
	if (n != 0) s = (char)(n + 48) + s;
	return s;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		cout << sum(a, b) << endl;
	}
	return 0;
}
