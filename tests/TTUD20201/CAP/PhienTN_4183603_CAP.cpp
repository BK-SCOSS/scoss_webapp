#include<bits/stdc++.h>
using namespace std;
const int MAX = 100007;
set<long long> A;
set<long long> B;
int main(){
    int t;
    cin >> t;
    while( t > 0){
        int res = 0;
        int n;
        cin >> n;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            A.insert(x);
        }
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> x;
            B.insert(x);
        }
        for(long long temp : A){
            if(B.count(temp) == 1){
                res++;
            }
        }
        cout << res << endl;
        t--;
    }

}
