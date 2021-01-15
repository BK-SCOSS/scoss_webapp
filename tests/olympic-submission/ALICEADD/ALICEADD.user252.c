#include <stdio.h>


int main() {
	unsigned long long arr[10];
	int i, j, t;
	unsigned long long m, n;
	scanf("%d", &t);
	
	for(i = 0; i < t; i++){
		scanf("%llu %llu", &m, &n);
		arr[i] = m + n;
	}
	for(i = 0; i < t; i++){
		printf("%llu\n", arr[i]);
	}

	return 0;
}
