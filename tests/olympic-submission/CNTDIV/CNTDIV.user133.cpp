#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long x = n*(n+1)*(n+2);
        long long y = x*x;
        int dem = 0;
        for(int i = 2; i < x; ++i){
            if(((x%i)!=0) && ((y%i) == 0)) ++dem;
        }
        cout << dem << "\n";
    }
    return 0;
}
