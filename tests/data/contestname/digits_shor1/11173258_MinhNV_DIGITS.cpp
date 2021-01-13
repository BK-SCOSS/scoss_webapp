#include <bits/stdc++.h>

using namespace std;
int a[7];
int update[10];
int ans, N;

void solution(){
    int T = a[0]*1000 + a[1]*100+a[2]*10010+a[3]*2+a[4]*1000+a[5]*100+a[6]*10;
    if(T == N){
        ans++;
    }
}

void init(){
    for(int i = 0; i <= 9; i++){
        update[i] = 0;
    }
}

void TRY(int k){
    for(int i = 0; i <= 9; i++){
        if(update[i] == 0){
            if(k == 0 || k == 2 ){
                if(i==0) continue;
            }
            a[k] = i;
            update[i] = 1;
            if(k == 6){
                solution();
            }
            else{
                TRY(k+1);
            }
            update[i] = 0;
        }
    }
}

int main(){
    int m;
    cin >> m;
    int rs[m];
    for(int i = 0; i < m; i++){
        cin >> N;
        init();
        ans = 0;
        TRY(0);
        rs[i] = ans;
    }

    for(int i = 0; i < m; i++){
        cout << rs[i] << endl;
    }

	return 0;
}
