#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        int N, T, T2;
        int dem1 = 0, dem2 = 0;
        int result = 0;
        scanf("%d", &N);
        T = N * (N + 1) * (N + 2);
        T2 = T * T;
        int* arrT = (int*)malloc(T/2*sizeof(int));
        int* arrT2 = (int*)malloc(T2/2*sizeof(int));
        for (int i = 1; i <= T/2; i++)
        {
            if (T % i == 0)
            {
                arrT[dem1++] = i;
            }
        }

        arrT[dem1++] = T;
        for (int i = 1; i <= T; i++)
        {
            if (T2 % i == 0)
            {
                arrT2[dem2++] = i;
            }
        }

        arrT2[dem2++] = T2;
        for (int i = 0; i < dem2; i++)
        {
            int flag = 0;
            for (int j = 0; j < dem1; j++)
            {
                if (arrT2[i] == arrT[j])
                    break;
                if (arrT2[i] < T)
                    flag++;
            }
            if (flag == dem1)
                result++;
        }
        printf("%d", result);
    }
    return 0;
}
