#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
	    unsigned long long a, b;
	    cin >> a >> b;
	    if((a/10)+(b/10) > 0)
	        cout << (a/10) + (b/10);
	    cout << (a%10) + (b%10) << endl;
	}
    return 0;
}
