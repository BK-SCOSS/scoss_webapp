#include<iostream>
#define MAX 101
#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int a[MAX];
int m;
int b[MAX];
vector<int> res;
void input(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cin >> m;
    for(int i = 1;i <= m; i++){
        cin >> b[i];
    }
}

int solve(){
    int cnt = 0;
    set<int> s;

    for(int i = 1; i <= n; i++){
        s.insert(a[i]);
    }

    for(int i = 1; i <= m; i++){
        if(s.find(b[i]) != s.end()){
            cnt++;
        }
    }

    return cnt;
}

int main(){
    cin >> t;
    while(t > 0){
        input();
        res.push_back(solve());
        t--;
    }

    for(int i = 0;i < res.size(); i++){
        cout << res[i] << endl;
    }
}