#include <iostream>
using namespace std;
 
int main() {
    int N,K;
	int x=0;
    cout << "Nhap so nguyen duong N: ";
    cin >> N;
    K = N*N;
    //cout << "Tat ca cac uoc cua so " << n << " la ";
    for(int i = 1; i <= K; i++) {
        if((K % i == 0) & (i>N)) {
        	x++;
            //cout << i << " ";
        }
    }
    return 0;
}
