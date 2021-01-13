#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int n, sum = 0;
	cin >> n;
	if(n <= 0 || n > 10){
		return 0;
	}
	else {
		int a[n][2];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			if(a[i][j] < 0){
				return 0; 		
			};
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			sum += a[i][j];
		}
		cout << sum << endl;
		sum = 0;
	}
	}
}
