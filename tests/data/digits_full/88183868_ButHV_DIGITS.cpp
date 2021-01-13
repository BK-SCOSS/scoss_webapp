#include<bits/stdc++.h>
using namespace std ;
#define MAX 100  

int n ;
int result = 0;
int mark[MAX] = {0} ;
int a[7] ;

bool check(int a[7]){
	for(int i=0; i<7; i++){
		if(a[0]==0||a[2]==0) return false ;
		if(1000*a[0]+100*a[1]+10*a[2]+a[3]+10000*a[2]+1000*a[4]+100*a[5]+10*a[6]+a[3]==n) return true ;
		else return false ;
	}
	
}

void TRY(int k){
	for(int i=0; i<=9 ; i++){
		if(mark[i]==0){
			a[k] = i ;
			mark[i] = 1 ;	
			if(k==6){
				if(check(a)){
					result += 1 ;
				}
			}
			else TRY(k+1) ;
			mark[i]	= 0 ;	
		}
			
	}
}

int main(){
	int t ;
	cin >> t ;
	for(int i=0; i<t; i++){
		cin >> n ;
		TRY(0) ;
		cout << result << endl ;
		result = 0 ;
	}
}



