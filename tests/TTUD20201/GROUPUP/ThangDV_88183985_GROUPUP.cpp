#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int T, n, i, sum, max;
	cin >> T >> n;
	while (n>=2 and n<=100000) {
		int a[n-1];
		int b[n-1];
		for (i=0; i<n; i++)
		   cin >> a[i];
		 
		int m=n;
		
		while (m>1){
		if(mod(m,2) == 0) {
			max=0;
			m=m/2;
			for (i=0; i<n; i=i+2){
				b[i] = a[i]+a[i+1];
				if (b[i]>max) max = b[i];
			}
			
			sum = sum+max;
		}   
		 if(mod(m,2) == 1) {
		 	max=0;
		 	m=(m-1)/2;
		 	for (i=0; i<n-1; i=i+2){
		 		b[i] = a[i]+a[i+1];
		 		if (b[i]>max) max = b[i];
			}
			if (a[n-1]>max) max = a[n-1]; 
		 }
	}
	cout << sum;
	}
}
