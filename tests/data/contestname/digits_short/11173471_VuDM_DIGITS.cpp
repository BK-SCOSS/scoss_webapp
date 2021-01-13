#include <bits/stdc++.h>
using namespace std;

int t, n[55];
int CS[7];
int result[55] = {0};
int visited[10];
int temp, ans = 0;

void init(){
	for(int i = 0; i < 10; i++)
		visited[i] = 0;
	ans = 0;
}

void solution(){
	unsigned long long S = 0;
	S = CS[0]*1000+CS[1]*100+CS[2]*10+CS[3]+CS[2]*10000+CS[4]*1000+CS[5]*100+CS[6]*10+CS[3];
	if (S == temp) ans++;
}

void TRY(int k){
	if(k == 0 || k == 2){
		for (int i = 1; i<=9; i++){
			if (visited[i] == 0){
				CS[k] = i;
				visited[i] = 1;
				TRY(k+1);
				visited[i] = 0;
			}
		}
	} else {
		for (int i = 0; i <= 9; i++){
			if(visited[i] ==0){
				CS[k] = i;
				visited[i] = 1;
				if (k==6)
					solution();
				else TRY(k+1);
				visited[i] = 0;
			}
		}
	}
}
	

int main(){
	cin >> t;
	for (int i = 1; i<= t; i++) 
		cin >> n[i];

	for (int i = 1; i<= t; i++){
		init();
		temp = n[i];
		TRY(0);
		cout << ans << endl;
	}
	
	return 0;
}
