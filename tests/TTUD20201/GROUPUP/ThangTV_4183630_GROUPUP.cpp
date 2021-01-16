#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
int main() {
    int t;
    cin>>t;
    while(t>=1){
        t--;
        cin>>n;
        int dem=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        while(n>1){
            int k;
            for(int i=2;i<=n;i++){
                if(i%2 == 0){
                    a[i] +=a[i-1];
                    swap(a[i],a[i/2]);
                }
            }
            if(n%2 ==1) {
                a[n/2+1]=a[n];
                n= n/2+1;
                k= n-1;
            }
            else {
                n=n/2;
                k=n;
            }
            int maxt=0;
            for(int i=1;i<=k;i++){
                maxt=max(maxt,a[i]);
            }
            dem +=maxt;
        }
         cout<<dem;
    }
}
