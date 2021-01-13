#include <stdio.h>

int main()
{
    long int n;
    scanf("%ld",&n);
    for(int i=0;i<n;i++)
    {
        long int a;
        scanf("%ld",&a);
        int cou =0;
        long int t = a*(a+1)*(a+2);
        for (int j=2;j<t;j++)
        {
            if (t%j!=0 && t*t %j==0)
                cou++;
        }
        printf("%d",cou);
    }
    return 0;

}
