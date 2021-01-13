#include <iostream>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;
int main() {
	long long q;
	long double n;
	cin>>q;
	long double dem=0;
	while(q--) {
		cin>>n;
		dem=0;
		long double t=n*(n+1)*(n+2);
		long double tt=t*t;
		for(long double i=2;i<t;i++) {
			if(tt/i==floor(tt/i)&&t/i!=floor(t/i)) dem++; 
		}
	cout<<setprecision(0)<<fixed<<dem;	
	}
}
