#include <stdio.h>

int SoUoc (int 	N){
	int T = N * (N+1) * (N+2);
	int dem = 0;
	for (int i = 1; i < T; i++){
		if((T*T) % i == 0 && T % i !=0){
			dem ++;
		}
	}
	return dem;
}

int main(){
	char Q;
	int N;
	scanf("%d", &Q);
	int output[Q];
	for (int i = 0; i < Q; i++){
		scanf("%d", &N);
		output[i] = SoUoc(N);
	}
	for (int i = 0; i < Q; i++){
		printf("%d\n", output[i]);
	}
	return 0;
} 
