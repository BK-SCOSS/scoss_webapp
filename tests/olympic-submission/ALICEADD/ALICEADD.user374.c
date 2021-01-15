#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T,i;
    unsigned int a,b;
    do{
        scanf("%d", &T);
    }while(T<0||T>=10);
    for(i=0;i<T;i++){
        scanf("%d", &a);
        scanf("%d", &b);
        printf("%d", a+b);
    }
    return 0;

}

