#include<iostream>
using namespace std;
#define ull unsigned long long
const ull mmc = 1e10;
int main() {
	ull a, b, c;
	a = 1e19;
	b = 1e19;
	int n;
	ull bn, ha, la, hb, lb;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > mmc || b > mmc) {
			bn = 0;
			la = a % (mmc);
			ha = a / mmc;
			lb = b%mmc;
			hb = b / mmc;
			c = la + lb;
			if (c > mmc) {
				c = c%mmc;
				bn = 1;
			}
			ull hrs = ha + hb + bn;
			cout << hrs << c << endl;
		}
		else {
			cout << a + b << endl;
		}
	}
	
	//system("pause");
	return 0;
}