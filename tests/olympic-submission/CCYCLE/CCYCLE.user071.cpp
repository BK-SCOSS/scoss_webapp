#include<bits/stdc++.h>
using namespace std;
int n , l , s , t;
int res , p = pow(10,9)+7;
int a[10001][10001];
void init(){
	for(int i = 1 ; i <= 3*n ; i++) for(int j = 1 ; j <= 3*n ; j++) a[i][j] = 0;
	a[1][2] = 1 ; a[1][3] = 1 ; a[1][3*n] = 1;
	a[2][1] = 1 ; a[3][1] = 1 ; a[3*n][1] = 1;
	for(int i = 1 ; i <= n ; i++){
		a[3*i+1][3*i] = 1; a[3*i][3*i+1] = 1;
		a[3*i+1][3*i+2] = 1; a[3*i+2][3*i+1] = 1;
		a[3*i+1][3*i+3] = 1; a[3*i+3][3*i+1] = 1;
	}
	res = 0;	
}
//void out(){
//	for(int i = 1 ; i <= 3*n ; i++){
//		for(int j = 1 ; j <= 3*n ; j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
void dfs(int f,int d, stack<int>S){
	S.push(f);
	if(d == l && f == t) {
		res++;
//		while(!S.empty()){
//			cout << S.top() << " ";
//			S.pop();
//		}
//		cout << endl;
		return;
	}
    if(d > l) return;
	for(int i = 1 ; i <= 3*n ; i++){
		if(a[f][i] == 1){
			dfs(i,d+1,S);
		}
	}
}
int main(){
   cin >> n >> l >> s >> t;
   stack<int>S;
   init();
//   out();
   dfs(s,0,S);
   cout << res << endl;
}

