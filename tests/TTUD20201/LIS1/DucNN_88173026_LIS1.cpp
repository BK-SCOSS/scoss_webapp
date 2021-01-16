#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
int final=1;

int check(int x,int *arr){
	for(int i=0;i<x-1;i++){
		stack<int> S;
		S.push(arr[i]);
		for(int j=i+1;j<x;j++){
			int temp=S.top();
			if(arr[j]-temp==1){
				S.push(arr[j]);
			}
		}
		int count=0;
		while(!S.empty()){
			S.pop();
			count++;
		}
		final=max(final,count);
	}
	return final;
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
