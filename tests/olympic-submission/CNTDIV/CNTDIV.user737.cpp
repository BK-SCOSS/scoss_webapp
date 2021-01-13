#include <iostream>
#include <math.h>
using namespace std;
int main() {
	long long n, t, count = 0,m,i;
	cin >> m;
	for(i=0;i<m;i++) {
		cin >> n;
		t = n * (n+1) * (n+2);
		for(i=1;i<t;i++) {
			if((t*t)%i==0&&t%i!=0) {
				count++;
			}
		}
		cout << count;
		count = 0;
	}
}
