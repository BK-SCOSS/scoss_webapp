#include<stdio.h>
#include<math.h>

/*int count(int x)
{
	int d=0;
	if (x==2) return 4;
	for (k=2; )
}*/

int main()
{
	int n,i, b[100];
	long int j,t,a[10000];
	scanf("%d", &n);
	for (i=0; i<n; i++) 
	{
		scanf("%li", &a[i]);
		t=a[i]*(a[i]+1)*(a[i]+2);
		b[i]=0;
		for (j=2; j<t; j++)
			if (t*t%j==0 && t%j!=0) b[i]++;
	}
	for (i=0; i<n; i++) printf("%d\n", b[i]);
	
	
}
