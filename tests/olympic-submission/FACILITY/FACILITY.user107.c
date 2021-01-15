#include<stdio.h>
void change(int x, int y)
{
	int tg;
	tg=x;
	x=y;
	y=tg;
}

/*int max(int x)
{
	int i;
	for (i=0; i<x-1; i++)
	  if (l[i]==l[x]-r[x] && h[i]<=s[x]) return i;
	return 0;
}*/

int main()
{
	int i,n,j,k ,maxx, s[100], h[100], d[100], r[100], l[100];
	scanf("%d%d", &n, &k);
	for (i=0; i<n; i++) 
	{
		scanf("%d %d %d", &s[i], &d[i], &r[i]);
		h[i]=s[i]+d[i]+k;
	}
	
	for (i=0; i<n; i++)
	  for (j=i+1; j<n; j++)
	  if (h[j]<h[i])
	  {
	  	change(h[i], h[j]);
	  	change(s[i], s[j]);
	  	change(r[i], r[j]);
	  	change(d[i], d[j]);
	  }
	l[0]=0;
	for (i=0; i<n; i++)
	  {
	  	l[i]=r[i];
		for (j=0; j<i-1; j++)
	    	if (h[j]<=s[i] && l[i]<l[j]+r[i])
	    	{
	    		l[i]=l[j]+r[i];
			}
	  }
    maxx=0;
	for (i=0; i<n; i++) 
	  if (maxx<=l[i]) 
	  {
	  	maxx=l[i];
	  }
	printf("%d", maxx);
	
}
