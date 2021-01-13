#include <iostream>
#define MAX 50

using namespace std;

int N;
int B[MAX];
int Q;
int Test;
int H, U, S, T, O, I, C;
int A[MAX];
int Bool[MAX] = {0};

void Try(int k, int N) {
	
    for (int i = 0; i <= 9; i++) {
        if (!Bool[i]) {
            A[k] = i;
            Bool[i] = 1;
            
            if (k == 9) {
            	
            	H = A[0];
            	U = A[1];
            	S = A[2];
            	T = A[3];
            	O = A[4];
            	I = A[5];
            	C = A[6];
            	
            	if (H != 0 && S != 0) {
           	    	int Sum = S * 10000 + (H + O) * 1000 + (U + I) * 100 + (S + C) * 10 + 2 * T;
            	
	            	if (Sum == N) {
	            		Q += 1;
					}
				}
            	

			}
                
            else
                Try(k + 1, N);
            Bool[i] = 0;
        }
    }
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin >> Test;
	
	for (int i = 0; i < Test; i++){
		cin >> N;
	    Try(0, N);
	    B[i] = Q / 6;
	    Q = 0;
	}
	
	for (int i = 0; i < Test; i++) {
		cout << B[i] << endl;
	}
	
    return 0;
}
