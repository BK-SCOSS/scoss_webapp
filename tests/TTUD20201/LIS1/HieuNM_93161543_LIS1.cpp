#include <bits/stdc++.h>

using namespace std;

long long maxcout(long long a, long long b) {
    if(a >  b) return a;
    else return b;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
    
    long long max = 0;
    long long n;
	cin >> n ;
	long long* a = new long long[n];
	
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for(long long t = 0; t < n; t ++) {
        long long res = 1;
        long long check = a[t];
		for(long long k = t + 1; k < n; k++) {
			if(a[k] == check+1 ) {
				res ++;
				check =  a[k];
               
			}
		}
        max = maxcout(max, res);
	}
	cout << max;


	delete[] a;

	}
}
