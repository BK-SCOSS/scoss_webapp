#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i=1; i<=T; i++){
        int n;
        cin >> n;
        long a[n],b[n];
        for (int i = 0; i<n; i++){
            cin >> a[i];
            b[i]=1;
            for (int j=i-1;j>=0;j--){
                if (a[i]-1==a[j]) {
                    b[i]=b[j]+1;
                    break;
                }
            }
        }

        int ans=0;
        for (int i=0; i<n; i++) {
            if (ans<b[i]) ans=b[i];
        }
        cout << ans;
    }
}
