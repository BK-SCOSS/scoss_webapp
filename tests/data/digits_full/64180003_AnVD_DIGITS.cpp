#include<bits/stdc++.h>
using namespace std;

int x[10] ;// U, S, T, O, I, C
int counter=0;
int H;
int N;
int digit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int check(){
	int result = H * 1000 + x[0] * 100 + x[1] * 10010 + x[2] * 2 + x[3] * 1000 + x[4] * 100 + x[5] * 10; 
	if(result != N)
		return 0;
	return 1;
}
void Try(int k){
	if(k == 6){
		if(check() == 1){
			counter++;
			//cout << H << x[0] << x[1] << x[2] << x[3] << x[4] << x[5] << endl;
			//cout << H << x[0] << x[1] << x[2] << "+" << x[1] << x[3] << x[4] << x[5] << x[2] << endl;
		}
			
	}
	else if(k == 1){
		for(int i=1; i<=9; ++i){
			if(!digit[i]){
				x[k] = i;
				digit[i] = 1;
				Try(k+1);
				digit[i] = 0;
			}
		}
	}
	else{
		for(int i=0; i<=9; ++i){
			if(!digit[i]){
				x[k] = i;
				digit[i] = 1;
				Try(k+1);
				digit[i] = 0;
			}
		}
	}
	
}

int main(){
	int T;
	long long temp;
	scanf("%d", &T);
	for(int i=0; i<T; ++i){
		counter = 0;
		scanf("%lld", &temp);
		if(temp > 109998 || temp < 12000){
			cout << counter << endl;
		}
		else{
			N = (int) temp;
			for(H=1; H<=9; ++H){
				digit[H] = 1;
				Try(0);
				digit[H] = 0;
			}
			cout << counter << endl;
		}
	}
}
