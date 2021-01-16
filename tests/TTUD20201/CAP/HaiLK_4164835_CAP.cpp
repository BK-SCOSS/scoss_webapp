#include<bits/stdc++.h>
using namespace std;

bool checkInArray(unsigned long long e, unsigned long long * arr, int length ){
    for(int i = 0; i < length; i++)
        if(e == arr[i]) return true;
    return false;
};

void xx(){
    int n, m, t;

    cin >> n;
    unsigned long long a[n];
    for(int i = 0; i <n; i++) cin >> a[i];

    cin >> m;
    unsigned long long b[m];
    for(int i = 0; i <m; i++) cin >> b[i];

    for(int i = 0; i <n; i++)
        for(int j = i+1; j <n; j++){
            if(a[i] > a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    // cout << a[-1];
    // return;
    
    int dem = 0;
    for(int i = 0; i <n; i++)
        if (i == 0 || a[i] != a[i-1])
            if(checkInArray(a[i], b, m)){
            dem += 1;
        }
    cout << dem << endl; 
}
int main(){
    
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i <T; i++)
        xx();
    return 0;
}