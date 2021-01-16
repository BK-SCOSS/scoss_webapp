#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100000];
int res[10];
int ans = 0;

int TRY(int *a, int n, int q){
    if(n==0) return ans;
    for(int i=0; i<n; i++){
        if(i>(n/2)){
            a[i] = 0;
            continue;
        }
        a[i] = a[i*2] + a[i*2+1];
        ans = max(ans, a[i]);
    }
    res[q] += ans;
    TRY(a, n/2, q);
}

int main(){
    cin >> k;
    for(int q=0; q<k; q++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        res[q]=0;
        TRY(a, n, q);
    }
    for(int i=0; i<k; i++){
        cout << res[i] << endl;
    }
}

