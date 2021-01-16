
#include <stdio.h>
#include <math.h>

const long max = 100000;

int MaxTwoNum(int a, int b){
    return (a > b ? a : b);
}

main()
{
    int n,t,k,m;
    int i,j,l;
    unsigned long a[max];
    int f[max];
    
    scanf ("%d", &t);
    
    for (l=1;l<=t;l++)
    
    {
    scanf("%d", &n);
    for (i=0;i<n;i++) scanf("%lu", &a[i]);
    
    int result = 1;
    for (int i=0; i<n; i++) {
    f[i] = 1;
    for (int j=0; j<i; j++) if (a[j] + 1 == a[i]) {
        f[i] = MaxTwoNum(f[i], f[j] + 1);
    }
    result = MaxTwoNum(result, f[i]);
}
    printf ("%d\n", result);
}
}
    
   
