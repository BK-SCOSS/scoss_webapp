#include<stdio.h>
void ham(){
    unsigned long a;
    unsigned long b;
    scanf("%d %d",&a,&b);
    printf("%d",a+b);
}
int main(){
    unsigned int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    ham();
    return 0;
}