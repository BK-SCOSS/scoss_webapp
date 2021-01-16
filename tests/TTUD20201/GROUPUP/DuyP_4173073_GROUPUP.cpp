#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int hop(int *a,int n){
	if(n==1) return 0;
	else{
		int max = 0;
		int x = n%2? (n/2+1): n/2;
		int b[x];
		if(n%2==0){
			for(int i=0;i<n-1;i+=2){
				b[i/2] = a[i] + a[i+1];
				max = max > b[i/2]? max:b[i/2];
			}
		}
		else {
			b[x-1] = a[n-1];
			for(int i=0;i<n-1;i+=2){
				b[i/2] = a[i] + a[i+1];
				max = max > b[i/2]? max:b[i/2];
			}
		}
		return max+hop(b,x);
	}
}

int main(){
	int n;
	int T;
	int* a;
	cin >> T ;
	for(int i=1;i<=T;i++){
		cin >> n;
		a = new int[n];
		for(int j=0;j<n;j++){
			cin >> a[j];
		}
		cout << hop(a,n)<<endl;
	}
}