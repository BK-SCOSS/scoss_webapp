#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int temp = 0;
		int n;
		cin >> n;
		int A[n];
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		
		std::sort(A, A+n);
		
		int m;
		cin >> m;
		int B[m];
		for(int i = 0; i < m; i++){
			cin >> B[i];
		}
		std::sort(B, B+m);
		
		for(int j = 0; j < m; j++){
			if(A[0] == B[j]){
				temp++;
				break;
			}
		}
		
		for(int j = 0; j < m - 1; j++){
			if(B[0] != A[0]){
				if(B[0] == A[j]){
					temp++;
					break;
				}
			}
		}
		
		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				if(A[i] == B[j] && A[i] != A[i-1] && B[j] != B[j-1]){
					temp++;
					break;
				}
			}
		}
		
		cout << temp << endl;
		
	}
	return 0;
}
