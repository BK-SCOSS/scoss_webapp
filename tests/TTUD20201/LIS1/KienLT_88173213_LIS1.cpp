#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int tinh(int a[], int n){
	int max=0;
	int b[n];
	for(int i=0; i<n; i++){
		b[i]=0;
	}
	
	for(int i=0; i<n; i++){
		int t=0;
		if(b[i]==1){continue;
		}
		else{
		
		for(int j=i+1; j<n; j++){
			if((a[j]-a[i]-t)==1){
				b[j]=1;
				t++;
				if(t>max){max=t;
				}
	             continue;
			}
		}
      }
	}
	return max+1;
}
int main(){
	int m; 
	cin >> m;
	for(int i=0; i<m; i++){
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		int s= tinh(a,n);
		cout << s;
	}
	
	return 0;
}
