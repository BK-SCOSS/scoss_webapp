#include<iostream>

using namespace std;

long long uoc(long long n) {
	long long t = n * (n + 1) * (n + 2);
	long long t2 = t * t;
	long dem = 0;
	for (int i = 1; i < t; i++) {
		if (t2 % i == 0 && t % i != 0) {
			dem++;
		}
	}
	return dem;
}

int main() {
	long long n;
	long long a[100000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cout << uoc(a[i]) << endl;
	}
	return 0;
}


