#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int nhom(int *a,int n){
	if(n==1) return 0;
	else{ 
	    int y;
		int m = 0;
		if( n%2==0) y=n/2+1;
		else y=n/2;
		int b[y];
		if(n%2==0){
			for(int i=0;i<n-1;i+=2){
				b[i/2] = a[i]+a[i+1];
				m = m > b[i/2] ? m : b[i/2];
			}
		}
		else{
			b[y-1] = a[n-1];
			for(int i=0;i<n-1;i+=2){
				b[i/2] = a[i]+a[i+1];
				m = m > b[i/2] ? m : b[i/2];
			}
		}
		return m+nhom(b,y);
	}
}
int main(){
	int t;
	cin >> t;
	int n;
	int* a;
	for(int i=1;i<=t;i++){
		cin >> n;
		a = new int[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		cout << nhom(a,n)<<endl;
	}
}
