#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	
	//
	
	for(int i =0; i< T; i++){
		int n;
		cin >> n;
		int A[n];
		for(int j =0; j<n; j++){
			cin >> A[j];
		}
		int m;
		cin >> m;
		int B[m];
		for(int k =0; k< m; k++){
			cin >>B[k];
		}
		
		//thuat toan:
		int count =0;
		for(int t=0; t<n; t++){
			for(int l=0; l<m; l++){
				if(A[t]==B[l]){
					count ++;
				}
			}
		}
		cout << count << endl;
	}
}
