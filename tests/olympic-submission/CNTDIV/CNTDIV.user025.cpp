#include<iostream>
using namespace std;
int main(){
	int Q;
	cin >> Q;
	unsigned int N[1000], count[1000];
	unsigned long long T[1000], K[1000];
	for (int i = 0; i < Q; i ++){
		cin >> N[i];
		T[i]=N[i]*(N[i]+1)*(N[i]+2);
		K[i]=T[i]*T[i];
	};
	for (int i = 0; i < Q; i ++){
		count[i]=0;
		for (int j = 1; j < T[i]; j ++){
			if (K[i] % j == 0 && T[i] % j != 0) count[i] ++;
		}
	};
	for (int i = 0; i < Q; i ++){
		cout << count[i] << endl;
	};
	return 0;
}
