#include <bits/stdc++.h>
using namespace std;
int arr[10000000];
int a;
int test(int i){
	int a1 = arr[i];
	int cnt = 1 ;
	for(int j = i+1 ; j < a ; j++){
			if(arr[j] == a1 +1){
				cnt = cnt + 1;
				a1 = arr[j];
			}
		}
	return cnt;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> a;
		int kq = 0;
		for(int i = 0 ; i < a ; i++){
			cin >> arr[i];
		}
		for(int i = 0 ; i < a ; i++){
			int cnt = test(i);
			if(kq >= a - i){
				break;
			}
			kq = max(kq,cnt);
		}
	cout << kq << endl;
	}
	return 0;
}
