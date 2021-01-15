#include <bits/stdc++.h>
using namespace std;

void xuly(int N){
	int dem = 0;
	unsigned long long T = N*(N+1)*(N+2);
	unsigned long long S = T*T;
	unsigned long long i;
	for(i=2; i<T; i++){
		if(S%i == 0 && T%i != 0){
			dem++;
		}
	}
	cout << dem << "\n";
}

int main(){
	int Q;
	cin >> Q;
	int data[Q];
	int tmp;
	for(int i = 0; i<Q; i++){
		cin >> tmp;
		data[i] = tmp;
	}
	
	for(int i = 0; i<Q; i++){
		xuly(data[i]);
	}
	return 0;
}

