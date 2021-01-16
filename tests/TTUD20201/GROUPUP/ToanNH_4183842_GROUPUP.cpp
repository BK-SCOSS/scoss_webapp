#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int j=1; j<=T; j++){
        int n;
        cin >> n;
        unsigned long a[n];
        for (int i=0;i<n;i++){
            cin >> a[i];
        }

        unsigned long ans = 0;
        while (n>1) {
            unsigned long maxtemp = 0;

            for (int i=0;i<n/2;i++){
                a[i]=a[i*2]+a[i*2+1];
                if (maxtemp<a[i]) maxtemp=a[i];

            }


            if (n%2==1) {
                a[n/2]=a[n-1];
                n=n/2+1;

            } else {
                n=n/2;

            }

            ans+=maxtemp;
        }
        cout << ans;
    }
}
