#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int dem_uoc(int so)
{
    int dem=0,tich,binh_phuong,i;
    tich=so*(so+1)*(so+2);
    binh_phuong=pow(tich,2);
    for(i=2;i<tich;i++)
    {
        if(tich%i!=0)
        {
            if(binh_phuong%i==0)
            {
                dem++;
            }
        } 
    }
    return dem;
}
int main()
{
    int Q;int*n,i;
    scanf("%d",&Q);
    n=(int*)malloc(Q*sizeof(int));
    for(i=0;i<Q;i++)
    {
        scanf("%d",&n[i]);
        n[i]=dem_uoc(n[i]);
    }
    for(i=0;i<Q;i++)
    {
        printf("%d\n",n[i]);
    }
}