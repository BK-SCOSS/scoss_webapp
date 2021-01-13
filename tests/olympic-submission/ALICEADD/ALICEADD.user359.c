#include <stdio.h>
#include <stdlib.h>

int main()
{
    short T;
    unsigned long a[10], b[10];
    do scanf("%d",&T);
    while (0>T && T>10);
    if(T>0)
    for (int i = 1; i<= T; i++ ){
        scanf("%lu %lu", &a[i], &b[i]);
    }
    for (int i = 1; i<= T; i++ ) printf("%lu\n", a[i]+b[i]);
    return 0;
}

