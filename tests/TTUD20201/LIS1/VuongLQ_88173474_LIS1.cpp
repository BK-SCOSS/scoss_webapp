#include <bits/stdc++.h>
using namespace std;

int main(){
	int test_case;
	cin >> test_case;
	for (int tc= 0; tc < test_case; tc++){
		long int n, dem = 0;
		cin >> n;
		long int a[n],b[n];
		for (long int i = 0; i < n; i ++){
			cin >> a[i];
			b[i] = 0;
		}
		for (long int i = 0; i < n; i ++){
			if (b[i] == 0){
				long int temp = a[i], count = 1, j = i;
				while (j < n){
					if (a[j] == (temp + 1)){
						count++;
						temp = a[j];
						b[j] = 1;
					}
					j++;
				}
				if (count > dem){
					dem = count;
				}
			}
		}
		cout << dem << endl;
	}
	return 0;
}
