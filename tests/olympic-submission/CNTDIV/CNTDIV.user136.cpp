#include <iostream>
#include <math.h>
using namespace std;



int main() {
	
	long int Q;
	cin >> Q;
	long long int n[Q], nem[Q], coun[Q], non[Q];
	long long int max = 0;
	for(long int i = 0; i < Q; i++) {
		cin >> n[i];
		non[i] = n[i]*(n[i]+1)*(n[i]+2);
		nem[i] = non[i]*non[i];
		coun[i] = 0;
		for(long long int j=1; j < non[i] ; j++) {
			if(nem[i]%j == 0 and non[i]%j != 0) {
				coun[i]++;
			}
		}
	}
	for(long int i = 0; i < Q; i++) {
		cout << coun[i] << endl;
	}
	
	return 0;
}
