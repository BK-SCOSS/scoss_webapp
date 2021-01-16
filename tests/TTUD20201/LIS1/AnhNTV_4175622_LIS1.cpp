#include<iostream>
#include<string.h>
#include <stack>

using namespace std;
int a[1000];
int mem[1000];
int n;

int lis(int i) {
	if (mem[i] != -1) {
		return mem[i];
	}
}
int main() {
	int mx = 0, pos = -1;
	for (int i = 0; i <= n; i++) {
		mx = max(mx, mem[i]);
		if (mx == mem[i])pos = i;


	}
	cout << mx;
	stack <int> s;
	for (int i = pos, k = 0; k < mx; ++k) {
		s.push(i);
		for (int j = 0; j < i; j++) {

			if (a[j] < a[i] && mem[j] + 1 == mem[i]) {
				i = j;
				break;
			}
		}
		while (!s.empty()) {
			cout << s.back();
			s.pop();
		}
	}
}
