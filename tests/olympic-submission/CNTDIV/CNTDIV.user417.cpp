#include <stdio.h>

int main()
{
    int Q;
    scanf("%d", &Q);
    for (int k = 1; k <= Q; k++)
    {
        unsigned long long n;
        scanf("%llu", &n);

        unsigned long long a[3] = {n, n + 1, n + 2};
        unsigned long long T = a[0] * a[1] * a[2];

        // printf("%llu\n", T);

        int count = 0;

        for (int i = 0; i < 3; i++)
        {
            unsigned long long tg;
            for (int j = i; j < 3; j++)
            {
                tg = a[i] * a[j];
                if (tg < T && T % tg != 0)
                    count++;
                // printf("%llu voi  %d\n", tg, count);

                for (int t = j; t < 3; t++)
                {
                    tg *= a[t];
                    if (tg < T && T % tg != 0)
                        count++;
                    // printf("%llu voi  %d\n", tg, count);
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}