#include<bits/stdc++.h>
using namespace std ;

int main(){
	int t ;
	cin >> t ;
	while(t>0){
		int n ;
		cin >> n ;
		int a[n] , s[99999] ;
		for(int i=0; i<n; i++){
			cin >> a[i] ;
		}
		
		int result  ;
		int index ;
		int pen = 0 ;
		
		for(int i=0; i<n-1; i++){
			index = i ;
			result = 1 ;
			for(int j=i+1; j<n; j++){
				if(a[j]-a[index]==1){
					result ++ ;
					index = j ;
				}
				s[pen] = result ;
				pen++ ;
//				cout << i << " " << result << endl ;
			}
		}
		
		int finalresult = 0 ;
		
		for(int i=0; i<pen; i++){
			if(finalresult<s[i]) finalresult = s[i] ;
//			cout << s[i] ;
		}
		
		t-- ;
		cout << finalresult ;
	}
}
