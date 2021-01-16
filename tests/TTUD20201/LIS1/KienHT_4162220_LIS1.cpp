#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >>T;
	for(int i =0; i< T; i++){
		int n;
		cin >>n;
		int A[n];
		for(int j =0; j< n; j++){
			cin >>A[j];
		}
		
	
		//thuat toan:
		int lengthmax =0;
		
		
		for(int k =0; k<n; k++){
			vector<int> vec;
			vec.push_back(A[k]);
			for(int t=1; t<n-k; t++){
				if(A[k]+1==A[k+t]){
					vec.push_back(A[k+t]);
					A[k]=A[k+t];
				}
			}
			if(vec.size()>lengthmax){
				lengthmax= vec.size();
			}
		}
		cout << lengthmax;
		
		
	}
}
