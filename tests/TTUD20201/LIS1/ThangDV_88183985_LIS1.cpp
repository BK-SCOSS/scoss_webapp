#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int T, n, i, j, k, l, max=1;
	
	cin >> T >> n;
	int a[n-1];
	
	for (i=0; i<n; i++)
	   cin >> a[i];
	   
	for (i=0; i<n; i++){
		k=1;
		l=a[i];
		for (j=i+1; j<n; j++){
			if (a[j]-l == 1){
				l++;
				k++;
			}
			} 
		if (k>max) max=k;	
		}
	for (int c=0; c<T; c++)	cout << max;	
	}
