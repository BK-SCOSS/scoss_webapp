#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int T, m, n, i, j, k=0;

	cin >> T >> n;
	int a[n-1];
	for (i=0; i<n; i++)
	 cin >> a[i];
	
	cin >> m;
	int b[m-1];
	for (j=0; j<m; j++)
	 cin >> b[j];
	 
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			if (a[i] == b[j]) k++; 
			
	}}
	
	cout << k;
}
	 
	 

