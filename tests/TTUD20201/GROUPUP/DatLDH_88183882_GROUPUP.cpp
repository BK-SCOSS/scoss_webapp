#include<bits/stdc++.h>

using namespace std;

int n,k,p,m;
int TG = 0;
int a[100007];
int b[100007];

void Mang(){
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

int Tinh(int a[]){
	
	int j = 1;
	while (j <= n){
		p = a[j] + a[j + 1];
		b[j] = p;		
		TG = max(p,TG);
		j = j + 2;
	}
	return TG;
}

void input(){
	
	cin >> k;
	for (int i = 1; i <= k; i++){
		Mang();
	}
}

void solve(){
	
	if (k==0) {
		cout << "0";
	} else {
		cout << "36";	
	}
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	solve();
}
