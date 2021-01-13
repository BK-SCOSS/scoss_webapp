#include <bits/stdc++.h>
using namespace std;

int T;
int n = 10;
int N;
bool ved[10];
int x[10];
int kq = 0;
int mark[10];


void inp(){
	cin >> N;
	for (int i = 0; i < 10; i++){
		mark[i] = 0;
	}
}

bool check(){
	int a = 1000 * x[1] + 100 * x[2] + 10 * x[3] + x[4];
	int b = 10000 * x[3] + 1000 * x[5] + 100 * x[6] + 10 * x[7] + x[4];
	return a + b == N ;
}

void go(int k){
	if (k>7){
		if (check()) kq++;
	return;	
	}
	for (int i = 0; i < 10; i++){
		if (i == 0){
			if (k == 1 || k == 3){
				continue;
			}
		}
		if (!mark[i]){
			mark[i] = 1;
			x[k] = i;
			go(k+1);
			mark[i] = 0;
		}
	}
}

int main(){
	cin >> T;
	for (int i = 0; i< T; i++){
		inp();
		go(1);
		cout << kq << endl;
		kq = 0;
	}
	return 0;
}
