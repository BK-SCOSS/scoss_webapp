#include <stdio.h>
int main()
{
    long int n;
    scanf("%ld",&n);
    unsigned long long a,b;
    for (int i=0;i<n;i++)
    {
        scanf("%llu%llu",&a,&b);
        printf("%llu\n",a+b);
    }
    return 0;
}
