#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int check(int *arr1, int *arr2,int n,int m){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr2[j]==arr1[i]&&arr2[j]>0){
				count++;
				arr2[j]=0;
			}
		}
	}

	return count;
}
	

 
int main()
{
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++){
		int n,m;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		cin>>m;
		int b[m];
		for(int j=0;j<m;j++){
			cin>>b[j];
		}
		
		cout<<check(a,b,n,m);
	}
	
	return 0;
}
   
