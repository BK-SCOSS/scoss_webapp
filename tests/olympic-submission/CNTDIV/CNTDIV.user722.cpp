#include<iostream>
using namespace std;

int main(){
	int Q;
	cin>>Q;
	int A[1000],B[10],C[10];
	int t;
	for(int i = 0 ; i < Q; i++){
		cin>>t;
		unsigned long long T = t*(t+1)*(t+2);
		int result = 0;
		for(int j = 1; j < T; j++){
			if(T*T%j == 0 && T%j != 0){
				result++;
			}
		}
		A[i] = result;
	}
	for(int i = 0; i < Q; i++){
		cout<<A[i]<<"\n";
	}
}
