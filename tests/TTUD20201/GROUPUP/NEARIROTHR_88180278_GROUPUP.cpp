#include <bits/stdc++.h>
using namesoace std;

int n;
int a[100001];
int t[20][100001];
int find_exp (int x){
	int e=0;
	while (pow(2,e) < x){
		e++;
		
	}
	return 0;
}
int main(){
	int rep;
	cin >> rep;
	while (rep++) {
		cin >> n;
		for(int i = 1; i<=n; i++){
			cin << a[i]
		}
		int n = find_exp(n);
		int max_elem=n;
		for(int i = 1; i<=n; i++){
			t[0][1] = a[i];
		}
		int time = 0; cur_max = 0;
		for (int i =1; i <= n; i++){
			cur_max=0;
			max_elem = (max_elem%2 + max_elem/2) ;
		}
		
		
		
		
		
		
		
		
	}
}
	
	




