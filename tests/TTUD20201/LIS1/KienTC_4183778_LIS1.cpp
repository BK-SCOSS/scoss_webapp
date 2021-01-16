#include <bits/stdc++.h>
using namespace std;
 
const int N=10005;

main(){
    int T, n ;
    long long a[N];
    stack<int> S;
    set<int> v;
    cin >> T >> n;
    for(int i = 1; i<=n; i++ ){
        cin >> a[i];
    }
    for(int i=1; i <= n; i++){
        for(int j = i ; j <= n; j++){
            if (S.empty()){
                S.push(a[i]);
            }
            else 
                if(a[j] == S.top() + 1 )
                    S.push(a[j]);
                    v.insert( S.size() );           
        }                     
        while (!S.empty())
        {
            S.pop();
        }  
    }
set<int>::iterator maxs = v.end();
    cout << *maxs;
}
    
