#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    int arr[T][2];
    int i,j;
    for(i = 0; i < T ; i++){
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }
    for(i = 0 ; i < T ; i++){
        int sum = 0;
        for(j = 0 ; j < 2 ; j++){
            sum+= arr[i][j];
        }
        printf("\n%d", sum);
    }
    return 0;
}