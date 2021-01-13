#include <iostream>
using namespace std;

int t, a[8], d[11];
int rev = 0;

void recursion(int step, int z);

int main() {
	
	cin >> t;
	while (t--) {
		int x; cin >> x;
		recursion(0, x);
		cout << rev << '\n';
		rev = 0;
	} 
	return 0;
}

void recursion(int step, int z) {
	if (step == 7) {
		if (!a[0] || !a[2]) return;
		int ans = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
		ans += a[2] * 10000 + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[3];
		
		if (ans == z) {
			++rev;
//			for (int i = 0; i < 7; ++i) {
//				cout << a[i] << ' ';
//			}
//			cout << '\n';
		}
		return;
	}
		
	for (int i = 0; i < 10; ++i) {
		if (d[i]) continue;
		a[step] = i;
		d[i] = 1;
		recursion(step + 1, z);
		d[i] = 0;
	}
}
