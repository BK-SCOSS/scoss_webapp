#include <iostream>
using namespace std;
int main(){
	unsigned long long a,b,c,a0,a1,b0,b1,c0,c1;
	int n;
	cin >> n ;
	while (n-- >0){
	cin >> a>> b;
	a0 = a % 10;
	a1 = a / 10;
	b0 = b % 10;
	b1 = b / 10;
	c0 = (a0 + b0)%10;
	c1 = (a0 + b0)/10;
	if ((a1+b1+c1)!=0) {
		cout << (a1+b1+c1) <<c0 << endl;
	}
	else cout << c0 << endl;
	}
}
