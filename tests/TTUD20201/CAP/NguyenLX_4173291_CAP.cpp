#include <bits/stdc++.h>
using namespace std;
#define N 100

int t;
int m, n;
int a[N];
int b[N];

void CAP() {
	int count = 0;
	for(int i=0; i<=n-1; i++) {
		for(int h=0; h<=m-1; h++) {
			if(a[i] == b[h])
				count = count + 1;
			}
		}
	cout << count;
	}

int main() {
	cin >> t;
	for(int i=0; i<=t-1; i++) {
		cin >> n;
		for(int j=0; j<=n-1; j++){ 
			cin >> a[j];
			}
		cin >> m;
		for(int h=0; h<=m-1; h++) {
			cin >> b[h];
			}
		}
	
	CAP();
	}
