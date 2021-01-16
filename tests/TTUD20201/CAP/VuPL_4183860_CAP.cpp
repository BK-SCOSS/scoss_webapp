#include<bits/stdc++.h>

using namespace std;

int T, n, m, cnt = 0;
long long a[105][105], b[105][105];
int mark[10000];
list<int> L;

void init(){
	//for(int i = 0; i < 10000; i++){
	//	mark[i] = 0;
	//}
	for(int i = 0; i < 1000; i++){
		L.push_back(0);
	}
}

bool check(long long a){
	for(auto it = L.begin(); it != L.end(); it++){
		if(a == *it) return false;
	}
	return true;
}

int main(){
	init();
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[T][j];
		}
		cin >> m;
		for(int j = 0; j < m; j++){
			cin >> b[T][j];
		}
	}
	
	for(int i = 0; i < T; i++){
		for(int j = 0; j < n; j++){
			for(int l = 0; l < m; l++){
				/*
				if(a[T][j] == b[T][l] && mark[a[T][j]] == 0){
					cnt++;
					mark[a[T][j]] = 1;
				}
				*/
				if(a[T][j] == b[T][l] && check(a[T][j])){
					cnt++;
					L.push_back(a[T][j]);
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
} 