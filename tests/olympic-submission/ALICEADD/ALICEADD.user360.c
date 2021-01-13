#include <stdio.h>

int main(){
    int t,i;
    unsigned long a,b;
    int kq[10];
    scanf("%d",&t);
    for (i=0; i<t; i++) 
    {  
        scanf("%d",&a);
        
        scanf("%d",&b);
        kq[i] = a + b;
        
    }
    for (i=0; i<t; i++) 
    {  
        printf("%d\n",kq[i]);
        
    }
    return 0;
}