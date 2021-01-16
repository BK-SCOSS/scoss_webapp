#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long int t, n, dem=1;
    cin >> t;
    while (t--){
        cin >> n;
        unsigned long long int a[n];
        for (unsigned long long int i=1; i<=n;i++){
            cin >>a[i];
        }
        for (unsigned long long int i=1; i<=n;i++){
            for (unsigned long long int j=i;j<=n;j++){
                if (a[j]-a[i]==1){
                    dem++;
                    i=j;
                }
            }
        }
        cout << dem <<endl;
    }
}
