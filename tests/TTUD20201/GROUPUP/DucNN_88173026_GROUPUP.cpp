#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
int Sum=0;

int check(int a,int *arr){
	if(a%2==0){
		int n=a/2;
		int X[n];
		for(int i=0;i<n;i++){
			X[i]=arr[2*i]+arr[2*i+1];
		}
		int MAX=X[0];
		for(int i=0;i<n;i++){
			if(MAX<X[i]) MAX=X[i];
		}
		Sum+=MAX;
		check(n,X);
	}
	else{
		int n=a/2;
		int X[n];
		for(int i=0;i<n;i++){
			X[i]=arr[2*i]+arr[2*i+1];
		}
		int MAX=X[0];
		for(int i=0;i<n;i++){
			if(MAX<X[i]) MAX=X[i];
		}
		int temp=MAX+arr[a-1];
		Sum+=temp;
		check(n,X);
	}
	return Sum;
}

int main(){
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<check(n,a);
	}
	
	return 0;
}
