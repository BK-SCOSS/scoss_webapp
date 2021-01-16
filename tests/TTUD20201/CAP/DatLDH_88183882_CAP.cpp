#include<bits/stdc++.h>

using namespace std;

int a[10007];
int b[10007];
int c[12];

int k,n,m;

void Mang(){
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}	
	
	cin >> m;
	for (int j = 1; j <= m; j++){
		cin >> b[j];
	}
}

void input(){
	
	cin >> k;
	int l = 0;
	
	for (int i = 1; i <= k; i++){
		Mang();
		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (a[i] == b[j]){
					l = l + 1;
					break;
				}
				else continue;
			}
		}
		
		c[i] = l;
		l = 0;
	}	
}

void solve(){
	
	for (int i = 1; i<= k; i++){
		cout << c[i] << endl;
	}
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	solve();
}
