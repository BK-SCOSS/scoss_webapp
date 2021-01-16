
#include <stdio.h>
#include <math.h>

const long max = 100000;

main()
{
    int m,n,t,k;
    int i,j,l;
    unsigned long a[max];
    unsigned long b[max];
    
    scanf ("%d", &t);
    
    for (l=1;l<=t;l++)
    
    { scanf("%d", &n);
    
      for (i=0;i<n;i++)
      {
       scanf("%lu", &a[i]);
          
      }
    scanf("%d", &m);
     
       for (j=0;j<m;j++)
      {
       scanf("%lu", &b[j]);
      }
      k=0;
      for ( i=0;i<n;i++)
      { for (j=0;j<m;j++)
        { if (a[i]==b[j]) {k+=1;}
         }
       }
       printf("%d\n",k);
    }
}
   
