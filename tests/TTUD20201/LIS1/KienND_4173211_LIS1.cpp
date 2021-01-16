#include<iostream>
#include <bits/stdc++.h>

int T, n, a[100001];
int i,j;

using namespace std;

int main(){
	cin >> T;
	for (int p = 0; p < T; p++) {
		int first, last, res = 0;
		cin >> n;
		for (i = 0; i < n; i++) cin >> a[i];
		while (n >= 0) {
			first = a[n-1]; last = a[n-1];
			n--;
			for (j = n-1; j >= 0; j--)
				if (a[j] == first - 1) {
					first = a[j];
					for (i = j; i < n; i++) a[i] = a[i+1];
					n--;
				}
			res = max(res, last - first + 1);
		}
		cout << res << endl;		
	}
}
