#include<stdio.h>
int main () {
	int q, a[100000], b[100000], c[100000];
	scanf ("%d", &q);
	for (int i = 1; i <= q; i++) {
		b[i] = 0;
		scanf ("%d", &a[i]);
		c[i] = a[i] * (a[i] + 1) * (a[i] + 2);
		for (int j = 1; j < c[i]; j++) if (c[i] * c[i] % j == 0 && c[i] % j != 0) b[i]++; 
	}
	for (int k = 1; k <= q; k++) printf ("%d\n", b[k]);
}
