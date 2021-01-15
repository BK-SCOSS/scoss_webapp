#include<iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	unsigned long long A[10],B[10],C[10];
	for(int i = 0 ; i < T; i++){
		cin>>A[i]>>B[i];
		C[i] = A[i]+B[i];
	}
	for(int i = 0; i < T; i++){
		cout<<C[i]<<"\n";
	}
}
