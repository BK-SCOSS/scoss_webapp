#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	string x[t];
	unsigned long long a, b;
	for(int i = 0; i < t; i++){
		x[i] = "";
		cin >> a;
		cin >> b;
		long e = a%10 + b%10;
		unsigned long long c = a/10 + b/10 + e/10;
		if(c > 0) x[i] = x[i] + to_string(c);
		x[i] = x[i] + to_string(e%10);
	}
	for(int i = 0; i < t; i++){
		cout << x[i] << endl;
	}
	return 0;
}
