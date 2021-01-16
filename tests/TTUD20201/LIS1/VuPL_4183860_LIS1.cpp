#include<bits/stdc++.h>

using namespace std;

int T, n, curLength = 0, maxLength = 0;
int a[10][10000], b[10][10000];
stack<int> S;

int main(){
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[T][j];
		}
	}
	
	for(int i = 0; i < T; i++){
		for(int j = 0; j < n; j++){
			S.push(a[T][j]);
			for(int k = j + 1; k < n; k++){
				int v = S.top();
				if(a[T][k] == v + 1) S.push(a[T][k]);
			}
			while(!S.empty()){
				curLength++;
				S.pop();
			}
			if(curLength > maxLength){
				maxLength = curLength;
			}
			curLength = 0;
		}
		cout << maxLength << endl;
	}
}