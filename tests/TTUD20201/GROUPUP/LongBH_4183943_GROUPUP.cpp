#include<iostream>
using namespace std;
const int MAX = 1e5;

int main() {
	int t, n, best = 0, time = 0;
	int a[MAX];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
			
		time = 0;
		while (n > 1) {
			if (n % 2 == 0) {
				for (int i = 1; i <= n - 1; i += 2) {
					a[(i+1)/2] = a[i] + a[i+1];
					best = max(best, a[(i+1)/2]);
				}
				time += best;
				n /= 2;
			}
			else {
				for (int i = 1; i <= n - 2; i += 2) {
					a[(i+1)/2] = a[i] + a[i+1];
					best = max(best, a[(i+1)/2]);
				}
				best = max(best, a[n]);
				a[(n/2)+1] = a[n];
				time += best;
				n = (n / 2) + 1;
			}
		}
		
		cout << time << endl;
	}
	
}
