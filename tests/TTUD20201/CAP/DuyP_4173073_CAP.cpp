#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int check(int *a,int index){
	int res = 1;
	if(index==0) return 1;
	else{
		for(int i=0;i<index;i++){
			if(a[i]==a[index]){
				res = 0;
				break;
			}
		}
	}
	return res;
}
int main(){
	int count;
	int T;
	cin >> T;
	int n,m;
	
	

	for(int i=1;i<=T;i++){
		count = 0;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}

		cin >> m;
		int b[m];
		for(int i=0;i<m;i++){
			cin >> b[i];
		}
		for(int j=0;j<n;j++){
			if(check(a,j)){
				for(int k=0;k<m;k++){
					if(a[j] == b[k]&&check(b,k)){
						count+=1;
						break;
					}
				}
			}
		}
		cout << count << endl;
	}
	
}