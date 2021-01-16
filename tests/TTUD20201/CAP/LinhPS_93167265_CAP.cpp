#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n,m; 
		int cnt = 0;
		cin >> n;
		int arr1[n];
		
		for(int i = 0 ; i < n ; i++){
			cin >> arr1[i];	
		}
		cin >>m;
		int arr2[m];
		for(int i = 0 ; i < m ; i++){
			cin >> arr2[i];
		}
		sort(arr1,arr1+n);
		sort(arr2,arr2+m);
		int max1 = 0;
		for(int i = 0 ; i < n ; i++){
			for (int j = 0; j <  m ; j++){
				if(arr1[i] == arr2[j]){
					if(arr1[i] != max1)
					{
						cnt++;
					}
					break;
				}
			}
		}
	cout << cnt << endl;		
	}
	
	return 0;
}
