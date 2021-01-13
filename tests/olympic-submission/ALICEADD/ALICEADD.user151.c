#include<stdio.h>
#include<stdlib.h>

int main()
{
    int T; 
    int *a,*b;
    int i=0, j=0;
    a=(int*)malloc(2*T*sizeof(int));
    b=(int*)malloc(T*sizeof(int));
    scanf("%d",&T);
    while(i<2*T)
    {
        scanf("%d %d",a+i,a+i+1);
        *(b+i)=*(a+i)+*(a+i+1);
        i=i+2;
    }
    while(j<2*T)
    {
        printf("%d \n",*(b+j));
        j=j+2;
    }
    free(a); free(b);
}