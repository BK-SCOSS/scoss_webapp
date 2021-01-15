#include <iostream>
#include <stdio.h>

using namespace std;

int numUOfN2(int N){
	int dem = 0;
	
	for (int i = 1; i < N; i++){
		if ((N*N % i == 0) && (N % i != 0)){
			dem++;
		}
	}
	return dem;
}

int main(){
	int numData;
	cin >> numData;
	
	int arr[numData];
	
	for (int i = 0; i< numData; i++){
		int N;
		cin >> N;
		arr[i] = numUOfN2(N*(N+1)*(N+2));
	}
	
	for (int i = 0; i < numData; i++){
		cout << arr[i];
	}
}
