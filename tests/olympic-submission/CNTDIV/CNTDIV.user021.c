#include <stdio.h>
int main()
{
    unsigned int k;
    scanf("%d", &k);
    unsigned int ket_qua[k];
    unsigned int z;
    for (z = 0; z < k; z++)
    {
        unsigned int n, t, i, count = 0;
        scanf("%u", &n);
        t = n * (n + 1) * (n + 2);
        for (i = 1; i < t; i++)
        {
            if (((t * t) % i == 0) && ((t % i) != 0))
            {
                count += 1;
            }
        }
        ket_qua[z] = count;
    }
    for (z = 0; z < k; z++)
    {
        printf("%u\n", ket_qua[z]);
    }
}