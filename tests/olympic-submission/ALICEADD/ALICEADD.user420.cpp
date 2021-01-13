#include<stdio.h>
int main () {
	int n;
	unsigned long long int a[10], b[10];
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%llu%llu", &a[i], &b[i]);
	for (int i = 1; i <= n; i++) printf ("%llu\n", a[i] + b[i]);
}
