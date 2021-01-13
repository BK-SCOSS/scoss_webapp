#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long a[n][2];
    for(int i=0; i<n; i++){
        scanf("%ld",&a[i][0]);
        scanf("%ld",&a[i][1]);
    }
    for(int i=0; i<n; i++){
        printf("%ld\n",a[i][0]+a[i][1]);
    }
}

