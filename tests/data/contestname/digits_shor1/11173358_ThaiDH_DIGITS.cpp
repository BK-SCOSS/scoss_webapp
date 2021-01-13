#include <bits/stdc++.h>
using namespace std;
const unsigned int N = 100000;

int main(){
	unsigned int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++ )
		cin >> a[i];
	long max = a[0];
	for(int i = 0; i < n; i++ )	
		for(int j = i; j < n; j++){
			int s = 0;
			for(int k = i; k <= j; k++)
				s = s + a[k];
			max = max < s ? s : max;
		}
	float x = max/n;	
	cout << x;
	return max;
}
