#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 105;
int t;
int rn[N], rm[N];
int res =  0;

void inp(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> rn[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> rm[i];
        for (int j = 0; j < n; j++){
            if (rm[i] == rn[j]){
                res++;
                break;
            }
          
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        inp();
        cout << res << endl;
        res = 0;
    }
}