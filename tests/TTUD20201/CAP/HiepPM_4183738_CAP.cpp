#include <bits/stdc++.h>

using namespace std;
int n,t,m;
map <long long, long long > s1, s2;


int cnt = 0;

void input(){
    int a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        s1[a] ++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b;
        s2[b] ++;
    }
}

void solve(){
    map <long long, long long > :: iterator it;
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 >= n2){
        for(it = s2.begin(); it != s2.end(); it++){
            long long a  =(*it).first;
            if(s1[a] != 0) cnt ++;
        }
    }
    else{
        for(it = s1.begin(); it != s1.end(); it++){
            long long a  =(*it).first;
            if(s2[a] != 0) cnt ++;
        }
    }
    cout << cnt << endl;
}

int main(){
    cin >> t;
    while(t--){
        input();
        solve();
        cnt = 0;
    }



}

