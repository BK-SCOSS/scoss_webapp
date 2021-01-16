#include<iostream>
using namespace std;

int countCap ( int a[] , int n , int b[], int m) {
	int count = 0;
	int marked[n];
	for ( int i = 0 ; i < n ; i++){
		marked[i] = 0;
	}
	for ( int i = 0 ; i < n-1 ; i++){
		for ( int j = i+1 ; j < n ; j++ ){
			if ( a[j] == a[i]){
				marked[j] = 1;
			} 
		}
	}
	for ( int i = 0 ; i < n ; i++){
		for ( int j = 0 ; j < m ; j++ ){
			if ( marked[i] == 0 ){
				if (a[i] == b[j]){
					count++;
					break;	
				} ;
			}
		}
	}
	return count;
}

//void printMarked( int arr[], int n) {
//	int marked[n];
//	for ( int i = 0 ; i < n ; i++){
//		marked[i] = 0;
//	}
//	for ( int i = 0 ; i < n-1 ; i++){
//		for ( int j = i+1 ; j < n ; j++ ){
//			if ( arr[j] == arr[i]){
//				marked[j] = 1;
//			} 
//		}
//	}
//	for ( int i = 0 ; i < n ; i++) cout<<marked[i]<<" ";
//}

int main(){
	int testNum;
	cin>>testNum;
	int ans[testNum];
	for ( int count = 0 ; count < testNum ; count++ ){
		int n, m;
		cin>>n;
		int arr1[n];
		for ( int i = 0 ; i < n ; i++){
			cin>>arr1[i];
		}
		cin>>m;
		int arr2[m];
		for ( int i = 0 ; i < m ; i++){
			cin>>arr2[i];
		}
		ans[count] = countCap(arr1, n, arr2, m);
	}
	for ( int count = 0 ; count < testNum ; count++ ){
		cout<<ans[count]<<endl;
	}
//	int n;
//	cin>>n;
//	int arr[n];
//	for ( int i = 0 ; i < n ; i++ ) cin>>arr[i];
//	printMarked(arr,n);
	return 0;
}
