#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    int a[11],b[11];
    for (i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for (i=1;i<=n;i++) printf("%d\n",a[i]+b[i]);
    return (0);

}