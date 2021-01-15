#include <stdio.h>

int main()
{
	int arr[10];
	int T, s;

	scanf("%d", &T);

	for (int i = 0; i < 2*T; ++i)
		scanf("%d", &arr[i]);

	for (int i = 0; i < T; ++i)
	{
		s = arr[2*i] + arr[2*i + 1];
		printf("%d\n", s);
	}

	return 0;
}