#include<bits/stdc++.h>

using namespace std;
int n;
int q;
int solve(int n){
    int res = 0;
    int t = n*(n+1)*(n+2);
    int t2 = t*t;
    for(int i = 3; i <t; i++){
        if(t2%i==0 && t%i != 0){
            res ++;
        }
    }
    return res;
}

int main(){
    cin >> q;
    while(q>0){
        cin >> n;
        cout << solve(n) << endl;
        q--;
    }
}

