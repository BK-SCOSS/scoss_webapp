#include<iostream>
#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n;
int a[MAX];


void input(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}



int solve(){
    int maxRes = 0;
    vector<int> res;
     for(int i = 1; i <= n; i++){
        res.push_back(a[i]);
    }
    while(res.size() != 1){
        int max = 0;
        vector<int> tmp;
        for(int i = 0; i < res.size()-1; i+=2){
            tmp.push_back(res[i]+res[i+1]);
            if(max < res[i]+res[i+1]) max = res[i]+res[i+1];
        }
        maxRes += max;
            

        if(res.size() % 2 != 0){
            tmp.push_back(res[res.size()-1]);
        }
        res.clear();

        for(int i = 0; i < tmp.size(); i++){
            res.push_back(tmp[i]);
        } 
    }
    return maxRes;
}

int main(){
    int t;
    vector<int> res;
    cin >> t;
    while(t>0){
        input();
        res.push_back(solve());
        t--;
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}