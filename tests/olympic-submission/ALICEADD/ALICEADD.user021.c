#include <stdio.h>
int main()
{
    int t, a, b, i;
    scanf("%d", &t);
    int ket_qua[t];
    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        ket_qua[i] = a + b;
    }
    for (i = 0; i < t; i++)
    {
        printf("%d\n", ket_qua[i]);
    }
}