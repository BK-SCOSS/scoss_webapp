#include <bits/stdc++.h>
using namespace std;

int n, k;
unsigned long long a[100000];
int x[100000];
int ans[10];

int main(){
    for(int i=0; i<10; i++){
        ans[i] = 1;
    }
    cin >> k;
    for(int q=0; q<k; q++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
            x[i] = 1;
        }
        for(int i=1; i<n; i++){
            if(a[i]==(a[i-1]+1)){
                x[i] = x[i-1] + 1;
                ans[q] = max(x[i], ans[q]);
            }
        }
    }
    for(int i=0; i<k; i++){
        cout << ans[i] << endl;
    }
}

