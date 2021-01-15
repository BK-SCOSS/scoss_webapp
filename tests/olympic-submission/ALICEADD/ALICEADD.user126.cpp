#include<stdio.h>

int main(){
	int x, i;
	int a[100];
	int b[100];
	scanf("%d", &x);
	for(i = 1; i<= x; i++){
		
	    scanf("%d %d", &a[i], &b[i]);
	    }
	for (i = 1; i<= x; i++){
		printf("%d\n", a[i]+b[i]);
		}
	return 0;
	}
