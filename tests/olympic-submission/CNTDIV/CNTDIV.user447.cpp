#include<bits/stdc++.h>
using namespace std;
unsigned long long N, Q, T, TT;
long cnt = 0;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> Q;
    while(Q--) {
        cin >> N;
        cnt = 0;
        T = N*(N+1)*(N+2);
        TT = T*T;
        for (int i = 2; i < T; i++){
            if(TT%i == 0 && T%i != 0) cnt++;
        }
        cout << cnt <<endl;
    }
    return 0;
}

