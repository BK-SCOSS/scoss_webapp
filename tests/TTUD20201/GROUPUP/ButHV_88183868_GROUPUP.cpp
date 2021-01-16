#include<bits/stdc++.h>
using namespace std ;

int result = 0  ;

int findmax(int b[], int n){
	int index = 0;
	for(int i=0; i<n; i++){
		if(index < b[i]) index = b[i] ;
	}
	return index ;
}

int solve(int s[] , int n){
	if(n==1) return result ;
	
	int m ;
	if(n%2==0) m = n/2 ;
	else m = n/2 + 1 ;
	
	int a[m] ;	

	if(n%2==0){
		for(int i=0; i<m; i++) a[i] = s[2*i] + s[2*i+1]  ;		
	}
	else{
		for(int i=0; i<m-1; i++){
			a[i] = s[2*i] + s[2*i+1]  ;			
		} 
		a[m-1] = s[n-1] ;
	}
		result += findmax(a,m) ;

	solve(a,m) ;
	return result ;
}


int main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ; 
		int a[n] ;
		for(int i=0; i<n; i++){
			cin >> a[i] ;
		}
		cout << solve(a,n) ;
	}
}
