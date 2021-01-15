#include <stdio.h>

int main()
{
	int T, a, b;
	int A[10];
	do
	{
		scanf("%d\n", &T);
	}
	while(T > 10);
	for(int i = 0; i < T; i++){
		scanf("%d %d", &a, &b);
		A[i] = a + b;
	}
	
	for(int i = 0; i < T; i++)
	{
		printf("%d\n", A[i]);
	}
	return 0;
}
