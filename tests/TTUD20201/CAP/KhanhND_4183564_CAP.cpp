#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int t;
int A[11][101];
int temp;
set<int> S;
int out;

void input(){
    cin >> t;
    for (int i = 0; i < t ; i++) {
        cin >> n;
        out = 0;
        for (int j = 0; j < n; j ++){
             cin >> temp;
             S.insert(temp);
        }
        cin >> m;
        for (int j = 0; j < m; j++){
            cin >> temp;
            if (S.find(temp) != S.end()){
                out ++;
            }
        }
        cout << out << endl;
        S.erase(S.begin(),S.end());
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    input();
}
