#include <stdio.h>
#include <math.h>


int main(){
	int n;

	do{
		scanf("%d", &n);
	}while(n <= 0);
	int a[n];
	int i = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int j = 0;
	unsigned int count[n];
	long long arr[n];
	
		for(i = 0; i < n; i++){
			count[i] = 0;
			arr[i] = a[i] * (a[i] +1) * (a[i] + 2);
			for(j = 1; j < arr[i]; j++){
			if((arr[i] * arr[i]) % j == 0 && arr[i] % j != 0){
				count[i] ++;
			}
		}
		
		}
		for(i = 0; i < n; i++){
			printf("%u\n", count[i]);
		}
	}
	
