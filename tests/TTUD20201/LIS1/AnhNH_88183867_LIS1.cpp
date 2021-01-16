#include<iostream>
#include<stdio.h>

using namespace std;

int  *a, n;
void input(){
	cin >> n;
	a = new int (n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		}
}

void sapxepday(int *a, int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(a[j] < a[i]) swap(a[i], a[j]);
			}
		}
}

int timday(int *a, int n){
	int count = 1;
	int max = 0;
	for(int i = 0; i < n; i++){
		if((a[i+1] - a[i]) == 1){
		count++;
		if(count > max) max = count;
		//max = max(count, max);	
		} else {
			count = 1;
			}
	}
	return max;
}

int main(){
	int T;
	cin >> T;
	for(int k = 0; k < T; k++){
		input();
		sapxepday(a, n);
		cout << timday(a, n) << endl;
		}
}
