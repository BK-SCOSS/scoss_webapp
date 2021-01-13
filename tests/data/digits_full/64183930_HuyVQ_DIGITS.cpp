#include<bits/stdc++.h>
using namespace std;

int T; // so bo test
int N; // Gia tri N dau vao
int A[7]; //Mang luu ket qua
int dem = 0; //dem so bo ket qua thoa man
int visited[10]; //mang luu cac chu so da duoc gan

bool UCV (int k, int i) {
	if (visited[i] != 0) return false;
	if (k == 0 && i == 0) return false;
	if (k == 2 && i == 0) return false;
	return true;
}

void digits(int k) {
	for (int i = 0; i <= 9; i++) {
		if (UCV(k, i) == true) {
			visited[i] = 1;
			A[k] = i;
			if (k == 6) {
				if (A[0]*1000+A[1]*100+A[2]*10010+A[3]*2+A[4]*1000+A[5]*100+A[6]*10 == N) dem++;
			}
			else digits(k+1);
			visited[i] = 0;
		}
	}	
}

int main() {
	cin >> T;
	while (T > 0) {
		T--;
		cin >> N;
		for (int i = 0; i < 10; i++) visited[i] = 0;
		digits(0);
		cout << dem <<endl;
		dem = 0;
	}
	return 0;
}
