#include <iostream>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int T;
	cin >> T;
	while (T>0) {
		unsigned long long a,b;
		cin >>a>>b;
		unsigned long long c=a%10;
		unsigned long long d=b%10;
		a=a/10;
		b=b/10;
		if ((a+b+(c+d)/10)!=0) cout<<(a+b+(c+d)/10);
		cout<<(c+d)%10;
		T--;
	}
	
	return 0;
}
