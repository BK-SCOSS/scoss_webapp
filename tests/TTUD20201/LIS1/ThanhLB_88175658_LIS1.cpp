#include <iostream>

#define MAXN 1000001
int n, a[MAXN];

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int k = 0; k < T; k++){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int S = 0;
		for (int i = 0; i < n; i++){
			for (int j = 1; j < n; j++){
				if (a[i] == a[j] + 1){
					S = S + 1;
					a[i] = a[j];
				}
			}
		}
		cout << S;
	}	
}

