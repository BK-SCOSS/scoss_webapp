
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[8];
int cnt = 0;
bool b[10];
bool check(int v,int k){
	if((v == 0 && k == 1) || (v == 0 && k == 3)) return false;
	if(b[v]) return true;
	return false;
}
void TRY(int k){
	for(int v = 0; v <= 9 ; v++){
		if(check(v,k)){
			a[k] = v;
			b[v] = false;
			if(k == 7){
				if((a[1]*1000 +a[2]*100+a[3]*10+a[4]+a[3]*10000+a[5]*1000+a[6]*100+a[7]*10+a[4]*1) == n){
					cnt ++;
				}
//				for(int j = 1; j <= 7; j++) cout << a[j] << " ";
//				cout << "\n";
			}
			else TRY(k+1);
			b[v] = true;
			
		
		}
	}
}
int main(){
	cin >> t;
	while(t){
		cin >> n;
		for(int i = 0; i < 10; i++) b[i] = true;
		TRY(1);
		cout << cnt << "\n";
		t = t -1;
	}
	
	return 0;
}
