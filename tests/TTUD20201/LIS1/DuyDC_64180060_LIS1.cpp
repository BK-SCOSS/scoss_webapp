#include <bits/stdc++.h>
using namespace std;

int n, *a;
map<int, int> mem;


void lis(int i){
	mem[a[i]] = 1;
	if(mem[a[i] - 1] != 0){
		mem[a[i]] = 1 + mem[a[i]-1];
	}
}


int main(){
	int t;
	cin >> t;
	while(t > 0){
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			mem[a[i]] = 0;
		}
//		mem = new int[n];
//		for(int i = 0; i < n; i++) mem[i] = 0; 
//		mem[0] = 1;
		int result = 0;
		for(int i = 0; i < n; i++) {
			lis(i);
			result = max(result, mem[a[i]]);
		}
		cout << result;
		t--;
	}
}
