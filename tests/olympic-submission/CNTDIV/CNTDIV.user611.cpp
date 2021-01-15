#include<bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;
    while(Q>0){
        int N;
        cin >> N;
        int T = N*(N+1)*(N+2);
        int T2 = T*T;

        int cnt = 0;
        for(int i=2; i<T; i++){
            if(T2 % i == 0 && T % i != 0) cnt++;
        }
        cout << cnt << endl;
        Q--;
    }
    return 0;
}
