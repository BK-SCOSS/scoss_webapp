#include<iostream>
using namespace std;

int nicestArr ( int arr[] , int n) {
	int longest = 0;
	int marked[n];
	for ( int i = 0 ; i < n ; i++) marked[i] = 0;
	int start = -1;
	while ( start < n){
		int longestNow = 1;
		start++;
		int currValue = arr[start];
		marked[start] = 1;
		for ( int i = start + 1; i < n ; i++ ){
			if (marked[i] == 0){
				if ( arr[i] == ( currValue + 1 ) ){
					marked [i] = 1;
					currValue ++ ;
					longestNow++ ;
				} 
			}
		}
		longest = max(longestNow,longest);
	}
	return longest;
}

int main(){
//	int n;
//	cin>>n;
//	int arr[n];
//	for ( int i = 0 ; i< n; i++){
//		cin>> arr[i];
//	}
//	int longest = nicestArr(arr,n);
//	cout<<longest;

	int testNum;
	cin>>testNum;
	int ans[testNum];
	for ( int i = 0 ; i < testNum ; i++ ){
		int n;
		cin>>n;
		int arr[n];
		for ( int j = 0 ; j < n ; j++ ){
			cin>> arr[j];
		}
		ans[i] = nicestArr(arr,n);
	}
	for ( int i = 0 ; i < testNum ; i++) {
		cout<< ans[i] <<endl;
	}
	return 0;
}
