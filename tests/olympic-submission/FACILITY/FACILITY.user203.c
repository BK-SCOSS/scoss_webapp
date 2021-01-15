#include<stdio.h>

void sx(int **A,int n){
    int i, j ;
    for(i = 0 ; i < n-1; i++){
        for(j = i+1; j< n; j++){
            if(A[i][0]> A[j][0]){
                int t1 = A[i][0], t2 = A[i][1], t3 = A[i][2];
                A[i][0] = A[j][0];
                A[j][0] = t1;
                A[i][1] = A[j][1];
                A[j][1] = t2;
                A[i][2] = A[j][2];
                A[j][2] = t3;
            }
        }
    }
}
int TimKiem(int **A , int n, int k, int j){
    int i  = 0; 
    for(i =j+1 ; i < n; i++){
        if(A[i][0] == k) return i;
    }
}

int main(){
    int  n, K, i ,j ;
    scanf("%d%d", &n, &K);
    int arr[n][3];
    for(i = 0 ; i < n ; i++){
        for( j =  0; j < 3 ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
        sx(arr,n);
        int max=0, max1=0;
        int f = 0;
        for( i = 0; i < n ; i++){
        while(f<n){
            max += arr[f][2];
            int m = arr[f][0]+arr[f][1] + K;
            if(TimKiem(arr,n,m,i)) f = TimKiem(arr,n,m,i);
        }
        if(max1<max) max1=max;
        }
        printf("%d", max1);
}