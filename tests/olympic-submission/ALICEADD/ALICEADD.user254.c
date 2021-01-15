#include<stdio.h>
int main()
{
 int t,i;
 long a[10],b[10],c[10];
 scanf("%d\n",&t);
 for(i=1;i<=t;i++)
  {
    scanf("%ld",&a[i]);
    scanf("%ld\n",&b[i]);
   c[i]=a[i]+b[i];
  }
  for(i=1;i<=t;i++)
   printf("%ld\n",c[i]);
}
