#include <stdio.h>

int main()
{
    int Q;
    scanf("%d", &Q);
    unsigned long N[Q];
    for (int i=0; i<Q; i++)
    {
        scanf("%lu", &N[i]);
    }
    for (int i=0; i<Q; i++)
    {
        unsigned long T[Q];
        T[i]=N[i]*(N[i]+1)*(N[i]+2);
        int count = 0;
        for (unsigned long j=1; j<T[i]; j++)
        {
            if (((T[i]*T[i])%j == 0) && (T[i]%j != 0)) count++;
            else count = count;
        }
        printf("%d\n", count);
    }
    getchar();
}
