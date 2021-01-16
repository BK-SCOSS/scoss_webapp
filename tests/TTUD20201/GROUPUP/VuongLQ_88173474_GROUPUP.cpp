#include <bits/stdc++.h>
using namespace std;
const long int MAX = 100000;
long int a[MAX];
long int SUM = 0;

void process(long int leng){
	if (leng == 0) {
		//SUM = SUM + a[leng];
	} else {
		long int temp = 0;
		if (leng%2 == 0){
			for (long int i = 0; i <= leng-1; i+=2){
				//cout << "i" << i << endl;
				a[i/2] = a[i] + a[i+1];
				if (a[i/2] > temp){
					temp = a[i/2];
				}
			}
			a[leng/2] = a[leng];
		} else{
			for (long int i = 0; i <= leng; i+=2){
				//cout << "i" << i << endl;
				a[i/2] = a[i] + a[i+1];
				if (a[i/2] > temp){
					temp = a[i/2];
				}
			}
		}
		//cout << "array sx" << endl;
		//for (int i = 0; i <leng; i++){
	//		cout << a[i];
	//}
	//	cout << endl;
		SUM = SUM + temp;
		process(leng/2);
	}
}
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);	
	int test_case;
	cin >> test_case;
	for (int tc= 0; tc < test_case; tc++){
		SUM = 0;
		long int n;
		cin >> n;
		for (long int i = 0; i < n; i ++){
			cin >> a[i];
		}
		process(n-1);
		cout << SUM << endl;
	}
	return 0;
}
