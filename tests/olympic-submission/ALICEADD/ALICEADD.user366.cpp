#if 1
#include<iostream>
#include<string>
using namespace std;
string Noi(string a, int n) {
	for (int i = 0;i < n;i++) {
		a =  '0'+a;
	}return a;
}
int main() {

	int T;
	cin >> T;
	string re[10];
	for (int i = 0;i < T;i++) {
		
		string a, b;
		cin >> a >> b;
		if (a.length() < b.length()) {
			a=Noi(a, b.length() - a.length());
		}
		else
		{
			b=Noi(b, a.length() - b.length());
		}
		int l = a.length();
		int nho = 0;
		for (int j = l - 1;j >= 0;j--) {
			int c = a[j] - '0' + b[j] - '0' + nho;
			nho = c / 10;
			re[i] = (char)(c % 10 + '0') + re[i];
		}if (nho == 1) {
			re[i] = '1' + re[i];
		}
	}for (int i = 0;i < T;i++) {
		cout << re[i] << endl;
	}
	return 0;
}
#endif