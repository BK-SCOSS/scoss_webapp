#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char xx[11][1000], yy[11][1000], kq[13][10000];
int cong(char a[], char b[], int u){
    int m, n , bd = 0, i, ok, x, tong[100];
    char c[100], h = '0';
    n = strlen(a);
    m = strlen(b);
    if(m > n){
        char dc[100];
        for(i = 0; i < m; i++){
            dc[i] = b[i];
        }
        for(i = 0; i < n; i++){
            b[i] = a[i];
        }
        for(i = 0; i < m; i++){
            a[i] = dc[i];
        }
        ok = m;
        m = n;
        n = ok;
    }
    for(i = 0; i < n - m; i++){
        c[i] = '0';
    }
    for(i = n - m; i < n; i++){
        c[i] = b[bd];
        bd ++;
    }
    for(i = n - 1; i >= 0; i--){
        tong[i + 1] =  (( a[i]  + c[i]  + h - 144 ) % 10) ;
        x = a[i]  + c[i]  + h - 144;
        h = '0';
        if(x > 9){
            h = '1';
        }
    }
    bd= 0;
    if(x > 9){
        tong[0] = 1;
        for(i = 0; i < n + 1; i++){
            kq[u][bd++] = '0' + tong[i];
            
        }
    }
    else{
       
        for(i = 1; i < n + 1 ; i++){
            kq[u][bd++] = '0' +tong[i];
        }
    } 
   
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> xx[i] >> yy[i];
        cong(xx[i], yy[i], i);
    }
    for(int i = 0; i < n; i++){
       printf("%s\n", kq[i]);
    }
    
       
    
}

