#include <stdio.h>

int main()
{
    int q,n,i,j,t;
    int uoc[1000];

    scanf("%d",&q);
    for (i=0;i<q;i++)
    {   uoc[i] =0;
        scanf("%d",&n);
        t=n*(n+1)*(n+2);
        for (j=1;j<t;j++)
        {
            if ((t*t%j==0)&&(t%j!=0))
            uoc[i]++;
        }
    }
    for (i=0;i<q;i++)
    {
        printf("%d\n",uoc[i]);
    }
}