#include <stdio.h>
#include <math.h>
int main()
{
    int T, a, b;
    do
        {scanf("%d", &T);} while(T<0 || T>10);
    int i, count[1000];
    for(i=0; i<T; i++)
        {do
           {
               scanf("%d%d", &a, &b);
           } while(a<0||a>pow(10,19)||b<0||b>pow(10,19));
         count[i]=a+b;}
    for(i=0; i<T; i++)
        printf("%d\n", count[i]);

}
