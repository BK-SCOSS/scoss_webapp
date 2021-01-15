#include<iostream>

using namespace std;

int main() {
	long long int q;
	long long int n;
	cin >> q;
	while (q--) {
		cin >> n;
		long long int res = n * (n + 1) * (n + 2);
		long long int after = res * res;
		
		long long int count = 0;
		for (int i = 2; i < res; i++) {
			if (after % i == 0 && res % i != 0)
			count ++;
		}
		cout << count << endl;
	}
}
