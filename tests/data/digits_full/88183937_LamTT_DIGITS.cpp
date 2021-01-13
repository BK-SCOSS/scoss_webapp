#include <iostream>
#define MAX 11

using namespace std;

int N;
int q = 0;
int H, U, S, T, O , I, C;
int A[MAX];
int Bool[MAX] = {0};

 
void Try(int k) {
    for (int i = 0; i <= 9 ; i++) {
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
            	
            	if ( H != 0 && S!= 0) {
					int Sum = S * 10000 + (H + O) * 1000 + (I + U) * 100 + (C + S) * 10 + 2 * T ;
            	
            		if (Sum == N) {
            			q += 1;
					}
				}
			}
                
            else
                Try(k + 1);
            Bool[i] = 0;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int T;
	cin >> T;
	int B[T];
	for (int i = 0; i < T; i++) {
		cin >> N;
		Try(0);
		B[i] = q / 6;
		q = 0;
	}
	
	for (int i = 0; i < T; i++) {
		cout << B[i] << endl;
	}
	return 0;

}
    
    
