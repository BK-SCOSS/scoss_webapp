#include <iostream>
#include <math.h>
#define MAX 100000000

using namespace std;

int T, n, c;
int a[MAX], mark[MAX];

int xuLy() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		xuLy();
	}
	
	cout << 0;
	return 0;
}
