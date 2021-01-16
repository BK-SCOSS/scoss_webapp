#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int hop(int *q,int n){
	if(n==1) return 0;
	else{
		int max = 0;
		int x = n%2? (n/2+1):n/2;
		int p[x];
		if(n%2==0){
			for(int i=0;i<n-1;i+=2){
				p[i/2] = q[i]+q[i+1];
				max = max > p[i/2] ? max : p[i/2];
			}
		}
		else{
			p[x-1] = q[n-1];
			for(int i=0;i<n-1;i+=2){
				p[i/2] = q[i]+q[i+1];
				max = max > p[i/2] ? max : p[i/2];
			}
		}
		return max+hop(p,x);
	}
}
int main(){
	int T;
	cin >> T;
	int n;
	int* a;
	for(int i=1;i<=T;i++){
		cin >> n;
		a = new int[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		cout << hop(a,n)<<endl;
	}
}

