#include <bits/stdc++.h>
using namespace std;
#define MAX 102

int test;
int n, m;
int rs;
int a[MAX], b[MAX];

int main() {
	cin >> test;
	for(int t =0; t<test; t++) {
		for(int i=0; i<MAX; i++) {
			a[i] = 0; b[i] = 0;
		}
		rs = 0;
		
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		cin >> m;
		for(int j=0; j<m; j++) {
			cin >> b[j];
			for(int i=0; i<n; i++) {
				if(b[j] == a[i]) {
					rs++;
					a[i] = 0;
				}
			}
		}
		cout << rs <<endl;
	}
}
