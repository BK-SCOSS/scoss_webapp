#include<iostream>

using namespace std;

string progress(string a, string b) {
	string temp = "";
	int m = a.size();
	int n = b.size();
	string res1 = a;
	string res2 = b;
	if (m < n) {
		res1 = b;
		res2 = a;
	}
	a = res1;
	b = res2;
	m = a.size();
	n = b.size();
	
	int carry = 0;
	string res = "";
	int sum = 0;
	int j = m - n;
	for (int i = n - 1; i >= 0; i--) {
		sum += carry + (a[i + j] - '0') + (b[i] - '0');
		if (sum >= 10) carry = 1;
		else carry = 0;
		sum = sum % 10;
		res = (char)(sum + '0') + res;
		sum = 0;
	}
	for (int i = j - 1; i >= 0; i--) {
		sum += carry + (a[i] - '0');
		if (sum >= 10) carry = 1;
		else carry = 0;
		sum = sum % 10;
		res = (char)(sum + '0') + res;
		sum = 0;
	}
	
	if (carry != 0) {
		res = (char)(carry + '0') + res;
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	string a, b;
	fflush(stdin);
	int c;
	while (t--) {
		cin >> a;
		cin >> b;
		cout << progress(a, b);
		cout << endl;
	}
	return 0;
}
