#include<iostream>
using namespace std;
int T, n, m;
int a[100], b[100];
int c[10000];
int MAX = 1000;
int count = 0;

int solve(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (a[i] == b[j] && c[a[i]] == 0){
			count++;
			c[a[i]] = 1;
			}
		}
	}
	return count;
}

int main(){
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		cin >> m;
		for(int k = 0; k < m; k++){
			cin >> b[k];
		} 
	solve();
	cout << count;
	count = 0;
	}
	return 0;
}
