#include<bits/stdc++.h>

using namespace std;

int a[100007];
int m[12];
int n,k;

void Mang(){
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

void input(){
	
	cin >> k;
	
	for (int i = 1; i <= k; i++){
		Mang();
		
		int c = 1;
		int d = 1;
		for (int i = 1; i <= n; i++){
			int q = a[i];
			int j = i + 1;
			while (j <= n){
				if (q == a[j] - 1){
					c = c + 1;
					q = a[j];
					i = j;
				} else j = j + 1;
			}
//			for (int j = i + 1; j <= n; j++){
//				if (q == (a[j] - 1)) {
//					c = c + 1;
//					q = a[j]; 
//				} 
//			}
			d = max(c,d);
			c = 0;
		}
		
		m[i] = d;
	}	
}

void solve(){
	
	for (int i = 1; i<= k; i++){
		cout << m[i] << endl;
	}
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	solve();
}
