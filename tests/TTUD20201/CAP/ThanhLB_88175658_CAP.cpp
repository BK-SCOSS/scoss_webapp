#include <iostream>

using namespace std;


int main() {
	int T;
	cin >> T;
	for (int x = 0; x < T; x++) {
		int n, a[100];
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		int m, b[100];
		cin >> m;
		for (int j = 0; j < m; j++){
			cin>> b[j];
		}
		int S = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i] == b[j])
					S = S + 1;
			}
		}
		cout << S;	
	}

}
