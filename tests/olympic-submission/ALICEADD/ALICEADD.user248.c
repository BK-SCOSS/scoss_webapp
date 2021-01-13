#include <stdio.h>

int main(){
	char T;
	unsigned long a,b ;
	scanf("%d", &T);
	unsigned long output[T];

	for (int i = 0; i < T; i++){
		scanf("%d %d", &a, &b);
		output[i] = a + b;
	}
	for (int i = 0; i < T; i++){
		printf("%d\n", output[i]);
	}
	return 0;
} 
