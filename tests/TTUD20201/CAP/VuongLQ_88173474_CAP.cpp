#include <bits/stdc++.h>
using namespace std;

int main(){
	int test_case;
	cin >> test_case;
	for (int tc= 0; tc < test_case; tc++){
		long int n,m,dem= 0;
		cin >> n;
		long int a1[n];
		for (long int i = 0; i < n; i ++){
			cin >> a1[i];
		}
		cin >> m;
		for (long int i = 0; i < m; i ++){
			long int temp;
			cin >> temp;
			for (long int j = 0; j < n; j ++){
				if (a1[j] == temp){
					dem++;
					break;
				}
			}
		}
		cout << dem << endl;
	}
	return 0;
}
