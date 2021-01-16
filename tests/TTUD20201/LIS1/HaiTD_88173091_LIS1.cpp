#include<iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int k =1; k<=T; k++){
		
	int n;
	cin>>n;
	int a[n];
	for( int i=0; i <n; i++){
		cin >> a[i];
	}
	int L[n];
	int Lmax = 0;
	int lengMax = 0;
	L[0] =1;
	for(int i =0; i<n;i++){
		for(int j = 0; j<i; j++){
			if(a[j] - a[i] == 1){
				if(L[j] > Lmax){
					Lmax = L[j]; 
				}
			}
		}
		L[i] = Lmax +1;
	
	}
		for (int i =1; i<n;i++){
		if(L[i] > lengMax){
			lengMax = L[i];
			}
		}
	cout << lengMax <<endl;	
}
return 0;
}
