#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int x[7]; // x[0] = H, x[1] = U, x[2] = S, x[3] = T, x[4] = O, x[5] = I, x[6] = C
int n;
int cnt=0;
int mark[10];

void solution(){
    int T = 0;
    T = (x[0]*1000 + x[1]*100 + x[2]*10 + x[3]) + (x[2]*10000 + x[4]*1000 + x[5]*100 + x[6]*10 + x[3]);

    if(T==n && x[0]!=0 && x[2]!=0){
        cnt++;
//    cout << T << " - ";
//    printf("%d%d%d%d + %d%d%d%d%d",x[0],x[1],x[2],x[3],x[2],x[4],x[5],x[6],x[3]);
//    cout << endl;

    }
}

void TRY(int k){
    for(int v=0;v<10;v++){
        if(mark[v]==0){
            x[k] = v;
            mark[v] = 1;
            if(k==6){
                solution();
            }
            else{
                TRY(k+1);
            }
            mark[x[k]]=0;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<10;i++){
            mark[i]=0;
        }

        cnt = 0;

        TRY(0);
        cout << cnt << endl;

    }
    return 0;
}
