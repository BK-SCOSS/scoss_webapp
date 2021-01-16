#include<bits/stdc++.h>
using namespace std ;

void check(int s[] , int n){
	 int result ;
	 int index = 0 ;
	 while(index < n){
	 	for(int i= index+1; i<n; i++){
	 		if(s[i]==s[index]) s[i] = -1 ;
		 }
		 index ++ ;
	 }
}

int main(){
	int t ;
	cin >> t ;
	while(t>0){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i=0; i<n; i++){
			cin >> a[i] ;
		}
		int m ;
		cin >> m ;
		int b[m] ;
		for(int i=0; i<m; i++){
			cin >> b[i] ;
		}
		check(a,n);
		check(b,m) ;
		int index = 0 ;
		int result = 0 ;
		while(index < n){
			for(int j=0; j<m ; j++){
				if(a[index]==b[j]&&a[index]>0) result++ ; 
			}
			index++ ;
		}
		t-- ;
		cout << result ;	
	}
}
