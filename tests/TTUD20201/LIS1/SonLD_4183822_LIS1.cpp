#include<iostream>
#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int t;
int n;
int a[MAX];
stack<int> s;

void input(){
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int solve(){
    for(int i = 1; i <= n; i++){
        s.push(a[i]);
    }

    int cnt = 1;
    int a = s.top();s.pop();
    while(!s.empty()){
        int b = s.top();
        if(a > b && a - b == 1) {
            cnt++;
            a = b;
            
        }
        s.pop();
    }
    return cnt;
}

int main(){
    cin >> t;
    vector<int> res;
    while(t > 0){
        input();
        res.push_back(solve());
        t--; 
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i]<< endl;
    }
}