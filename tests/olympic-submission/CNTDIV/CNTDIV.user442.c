#include <stdio.h>
#include <stdlib.h>

void demUoc(int N, int Q, int vtri,int KQ[])
{
    long T = N * (N + 1) * (N + 2), i, dT = T * T;

    for (i = 1; i < T; i++)
    {
        if ((dT % i == 0) && (T % i != 0))
        {
            KQ[vtri]++;
        }
    }
}

int main()
{
    int Q, i = 0, *KQ, N;
    if (scanf("%d", &Q) == 1)
    {
        KQ = (int *) calloc(Q, sizeof(int));
        if(KQ == NULL) return 1;
        for (; i < Q; i++)
        {
            if (scanf("%d", &N) == 1)
            {
                demUoc(N, Q, i, KQ);
            }
            else
            {
                return 1;
            }
            
        }
    }
    else
    {
        return 1;
    }

    for (i = 0; i < Q; i++)
    {
        printf("%d\n", KQ[i]);
    }
    
    
    free(KQ);
}