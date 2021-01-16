#include<iostream>
using namespace std;

void refactorArray( int oldArr[] , int n ) {
	int index = 0 ;
	int indexNewArr = 0;
	while ( index < n ) {
		oldArr[indexNewArr] = oldArr[index] + oldArr[index+1];
		indexNewArr++;
		index = index + 2;  
	}
	int lastGroup = oldArr[n-1];
	//cout<< lastGroup << endl;
	if (index == (n+1)) oldArr[n/2] = lastGroup;
	for ( int i = n/2+n%2 ; i < n ; i++ ) oldArr[i] = 0 ;
}

int maxTimeCount( int arr[], int n) {
	int maxTime = 0 ;
	for ( int i = 0 ; i < n ; i++) {
		maxTime = max(maxTime, arr[i]);
	}
	return maxTime;
}

int main(){
	int testNum;
	cin>>testNum;
	int ans[testNum];
	for ( int i = 0 ; i < testNum ; i++ ){
		int n;
		cin>>n;
		int arr[n];
		for ( int j = 0 ; j < n ; j++ ) cin >> arr[j];
		long totalCost = 0;
		while ( arr[1] != 0 ){
			refactorArray(arr,n);
			totalCost += maxTimeCount(arr,n); 
		}
		ans[i] = totalCost;
	}
	for ( int i = 0 ; i < testNum ; i++) cout<<ans[i]<<endl;
	return 0;
}
