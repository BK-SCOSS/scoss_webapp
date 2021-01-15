#include<bits/stdc++.h>
using namespace std;

main(){
	int Q;
	int N;
	cin >> Q;
    for(int i = 1; i <= Q; i ++){
        cin >> N;
        long long res = 0;
        long long T = N*(N+1)*(N+2);
        for(int i = 1; i <= T; i ++){
            if(T*T % i == 0 && T % i != 0){
                res ++;
            }
        }
        cout << res;
    }
}
