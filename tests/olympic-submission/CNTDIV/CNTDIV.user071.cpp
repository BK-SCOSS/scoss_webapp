#include <bits/stdc++.h>
using namespace std;


int main(){
    int test;
    queue <int> save;
    cin >> test;
    while(test--){
        long long t, n, T;
        cin >> n;
        t = n*(n+1)*(n+2);

        T = t*t;
  
        int coun1=0, coun2=0;
        long long a = sqrt(t);
    
        for(long long i=1; i<t; i++){
            if(t%i==0)
                coun1 ++;
        }
        for(long long i=1; i<t; i++){
            if(T%i==0)
                coun2 ++;
        }
        save.push(coun2-coun1);
    }
    while(!save.empty()){
        cout << save.front() << endl;
        save.pop();
    }
        
    
}