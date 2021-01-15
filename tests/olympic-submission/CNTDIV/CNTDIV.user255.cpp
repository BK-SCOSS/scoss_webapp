#include <iostream>
#include <iostream>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int Q;
	cin>>Q;
	while (Q>0) {
		int n;
		int count=0;
		cin >>n;
		unsigned long long T=n*(n+1)*(n+2);
		unsigned long long K=T*T;
		for (int i=2;i<T;i++) {
			if (T%i!=0) {
				if (K%i==0) count++;
			}
		}
		cout<<count<<endl;
		Q--;
	}
	return 0;
}
