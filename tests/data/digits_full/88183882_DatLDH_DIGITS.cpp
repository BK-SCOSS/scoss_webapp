#include <iostream>

using namespace std;

int H, U, S, T, O, I, C, N;
int k, v, x;
int A[100005];
int B[100005];
int E[100005];

void Try(int k, int N){
	for (int i = 0; i <= 9; i++){
		if (!B[i]){
			A[k] = i;
			B[i] = 1;
			
			if (k == 9) {
				H = A[0];
				U = A[1];
				S = A[2];
				T = A[3];
				O = A[4];
				I = A[5];
				C = A[6];
				
				if ((H != 0) && (S != 0)) {

					int Sum = S*10000 + (O + H)*1000 + (I+U)*100 + (C+S)*10 + T*2;
					
					if (Sum == N) {
						x = x+1;
					}
  				}
			}
			else Try (k+1, N);
			B[i] = 0;
		}
	}
}

main(){
	cin >> v;
	for (int i = 0; i < v; i++){
		cin >> N;
		Try(0,N);
		E[i] = x/6;
		x = 0;
	}
	
	for (int i = 0; i < v; i++){
		cout << E[i] << endl;
	}
	
	return 0;
	
}
