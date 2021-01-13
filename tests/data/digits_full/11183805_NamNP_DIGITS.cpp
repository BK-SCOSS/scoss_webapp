#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;


int n;
int main(){
	int tmp_test;
	scanf("%d",&n);	
	for(int i = 0; i < n; i++){
		scanf("%d",&tmp_test);
		if((tmp_test % 2 == 1) || tmp_test > 99999 || tmp_test < 1100){
			printf("0\n");
			continue;		
		}
		int T = (tmp_test % 10) / 2;
		int S = tmp_test / 10000;
		if(S == T) {			
			printf("0\n");		
			continue;
		}		
		int C = ((tmp_test % 100) / 10 - S) ;
		if(C == T || C == S){
			printf("0\n");		
			continue;
		}
		int I_U = (tmp_test % 1000) / 100;
		int O_H = (tmp_test % 10000) / 1000;
		int result = 0;
		for(int I = 0; I < 10; I++){
			if(I > I_U) continue;
			if(I == T || I == C || I == S ) continue;
			int U = I_U - I;				
			if(U == T || U == C || U == S || U == I ) continue;
			for(int O = 0; O < 10; O++){
				//printf("%d %d \n",I,U);				
				if(O > O_H) continue;
				if(O == T || O == C || O == S || O == I || O == U) continue;
				int H = O_H - O;	
				//printf("%d %d %d %d %d %d %d\n",S,T,C,H,O,U,I);			
				if(H == T || H == C || H == S || H == I || H == U || H == O) continue;
				result++;			
			}
		}
		printf("%d",result);


	}	
	return 0;
}
