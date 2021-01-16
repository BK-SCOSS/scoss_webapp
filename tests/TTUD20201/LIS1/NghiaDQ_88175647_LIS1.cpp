#include <bits/stdc++.h>

using namespace std;


int main(){
    int x;
    cin >> x;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for(int j = 0; j < m; j++){
        cin >> b[j];
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            c++;
        }

    }
    for(int j = 0; j < m; j++){
        if(b[j]  == x){
        c++;
    }
    }
    cout << c;
}
