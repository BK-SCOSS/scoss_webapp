#include<stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    for (int i  = 0 ; i < a; i ++ ){
        int x; int y;
        scanf("%d %d", &x,&y);
        printf("%d\n",x + y);
    }
}
