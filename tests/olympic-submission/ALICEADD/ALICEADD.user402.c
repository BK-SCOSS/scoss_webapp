#include <stdio.h>
#include <math.h>

int main(){
	int n;
	unsigned long long a, b;
	unsigned long long tong[10] ;
	do{
		scanf("%d", &n);
	}while(n < 0 || n > 10);
	fflush(stdin);
	int i = 0;
	for(i = 0; i < n; i ++){
		scanf("%llu %llu", &a, &b);
		tong[i] = a + b;
	}
	for(i = 0; i < n; i++){
		printf("%llu\n", tong[i]);
	}
	
}
