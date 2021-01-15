#include <stdio.h>
main()
{
      int m,n,i,j,sum=0;
      int a[10][2];
      // enter matrix n rows and m colums
      do{scanf("%d",&n);
	}
	while (n<=0||n>10);
      
      for(int i=0;i<n;i++)
          for(int j=0;j<2;j++)
         {
         scanf("%d",&a[i][j]);
         }
         // process matrix.
      for(int i=0;i<n;i++)
      {
       for(int j=0;j<2;j++)
        {
         sum+=a[i][j];     
        }
       printf("%d\n",sum);
       sum=0;
      }
}
