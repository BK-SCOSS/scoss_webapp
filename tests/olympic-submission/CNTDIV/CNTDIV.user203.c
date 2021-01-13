#include<stdio.h>
#include<math.h>
int count(int N){
    int i, c = 0;
    int T = N*(N+1)*(N+2);
    for(i = 1 ; i <= T ; i++){
        if((T*T)%i == 0 && T%i != 0) c++;
    }
    return c;
}
int main(){
    int n;
    scanf("%d", &n);
    int i, arr[n];
    for( i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for( i =0 ; i< n; i++){
        printf("\n%d", count(arr[i]));
    }
    return 0;
}