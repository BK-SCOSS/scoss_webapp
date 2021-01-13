#include <iostream>
using namespace std;
int main(){
	int T, i;
	unsigned long long A[10], B[10];
	cin >> T;
	for(i=0; i<T; i++){
		cin >> A[i] >> B[i];
	}
	for(i=0; i<T; i++){
		cout << A[i] + B[i] << endl;
	}
}
