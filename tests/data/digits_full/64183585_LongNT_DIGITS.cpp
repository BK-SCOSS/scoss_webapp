#include <iostream>

using namespace std;
int m,n[50];int ans[50];
int d[7]; //s,o,i,c,t,h,u;
int check[10];

void find_k(int k,int j){
    if(k == 7){
        if(10010*d[0] + 1000*d[1]+100*d[2]+10*d[3]+2*d[4]+1000*d[5]+100*d[6] == n[j]){
            //for(int i=0;i<7;i++) cout << d[i] << " ";
            ans[j] ++;
        }
    }
    if(k == 4){
        int i = n[j]%10/2;
        if(check[i]==0){
            check[i] = 1;
            d[k] = i;
            find_k(k+1,j);
            check[i] = 0;
        }
        i = n[j]%10/2 +5;
        if(check[i]==0){
            check[i] = 1;
            d[k] = i;
            find_k(k+1,j);
            check[i] = 0;
        }
    }else{
        for(int i = 0; i<=9;i++){
            if((k == 0 || k == 5)&& i==0) continue;
            if(check[i] ==0){
                d[k] = i;
                check[i] = 1;
                find_k(k+1,j);
                check[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> m;
    for(int j=0; j<m; j++){
        ans[j] = 0;
        cin >> n[j];

    }
    for(int j=0; j<m;j++){
        for(int i=0; i<7;i++) check[i] = 0;
        if(n[j]%2 == 0) find_k(0,j);
        cout << ans[j] << "\n";
    }
}
