#include <iostream>
using namespace std;

int main(){
	long Q,T;
	cin >> Q;
	long i = 0, j = 1;
	
	for (i = 0; i<Q; i++){
		long n, dem = 0;
		cin >> n;
		T = n*(n+1)*(n+2);
		for (j = 1; j<T; j++){
			if (((T*T)%j==0) && (T%j!=0)){
				dem++;
			}
		}
		cout << dem << endl;
	}

	return 0;
}
