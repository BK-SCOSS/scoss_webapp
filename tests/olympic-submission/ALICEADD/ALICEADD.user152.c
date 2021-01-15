#include <stdio.h>
#include <math.h>
int main()
{
    int T;
    int a,b;
    do
        {scanf("%d", &T);} while(T<0 || T>10);
    int i;
    int count[1000];
    for(i=0; i<T; i++)
        {do
           {
               scanf("%d%d", &a, &b);
           } while(a<0 || b<0 );
         count[i]=a+b;}
    for(i=0; i<T; i++)
        printf("%d\n", count[i]);
    return 0;
}
