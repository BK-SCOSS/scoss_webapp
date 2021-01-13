#include<stdio.h>
 int n;
 unsigned long long a[11][3];


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%llu%llu", &a[i][0], &a[i][1]);
    }

    for(int i = 0; i < n; i++){
        printf("%llu\n", a[i][0] + a[i][1]);
    }


    return 0;
}