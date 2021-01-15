
#include<stdio.h>
int main(){
    int q;
    int n;
    int t;
    int i=0;
    int j=0;
    int dem=0;
    int T;
    scanf("%d",&q);
    for(i=0;i<q;i++ ){
        scanf("%d",&n);
        dem=0;
        t=n*(n+1)*(n+2);
        T=t*t;
        for(j=2;j<t;j++){
            if((t%j)!=0&&(T%j)==0)
            dem++;
        }
        printf("%d\n",dem);
    }
}