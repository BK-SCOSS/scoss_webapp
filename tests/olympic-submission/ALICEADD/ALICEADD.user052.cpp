#include<iostream>

using namespace std;

int main(){
	int n, a[100001][2];
	cin >> n;
	for (int i=0;i<n;i++){
		for (int j=0;j<=1;j++){
			cin >> a[i][j];
		}
	}
	for (int i=0;i<n;i++){
		int S=0;
		for (int j=0;j<=1;j++){
			S = S+a[i][j];
			
		}cout << S << endl;
	}
	return 0;
}
