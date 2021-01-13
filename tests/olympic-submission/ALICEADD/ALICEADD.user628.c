#include<stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T > 0 && T <= 10)
	{
		unsigned long long a, b;
		scanf("%llu%llu", &a, &b);
		printf("%llu\n", a + b);
		T--;
	}
	return 0;
}
// 10000000000000000000 0