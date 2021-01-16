#include<bits/stdc++.h>
using namespace std;
const int maxN=1e7+3;
int T;
int n;
int t;
int a[maxN];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        t=0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        int j=1;
        int i=1;
        int tem=0;
        while(n!=1){
            a[j]=a[i]+a[i+1];
            tem=max(tem, a[j]);
            j++;
            i+=2;
            if(i>=n){
                if(i==n){
                    a[j]=a[i];
                    tem=max(tem,a[j]);
                }
                t=t+tem;
                i=1; j=1;
                n=n/2+n%2;
                tem=0;
            }
        }
        cout << t;
    }
    return 0;
}
