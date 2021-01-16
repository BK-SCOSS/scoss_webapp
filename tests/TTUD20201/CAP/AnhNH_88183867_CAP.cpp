#include<stdio.h>
#include<iostream>

using namespace std;

int T, n, m;
int *a, *b;
//, a[n], b[m];

int soptchung(int *a, int n, int *b, int m){
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] == b[j] && a[i] > 0 && b[j] > 0) count++;
			}
		}
	return count;
	}
	
void input(){
	cin >> n;
	a = new int(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] == a[i]) {
				a[j] = -1;
				break;
				}
			}
	cin >> m;
	b = new int(m);
	for(int i = 0; i < m; i++){
		cin >> b[i];
		}
	for(int i = 0; i < m - 1; i++){
		for(int j = i + 1; j < m; j++){
			if(b[j] == b[i]) {
				b[j] = -1;
				break;
				}
			}
	}

}
}


int main() {
	cin >> T;
	int kq[T];
	for( int k = 0; k < T; k++){
		input();
		kq[k] = soptchung(a, n, b, m) ;
	}
	for( int k = 0; k < T; k++){
		cout << kq[k] << endl;
		}
}
	
	
	
	
	
	
