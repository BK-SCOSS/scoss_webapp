#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        int n;
        cin >> n;
        int sum = 0;
        int a[100001];
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        while(n>1){
            int j = 1;
            for(int i=1; i<=n; i=i+2){
                a[j] = a[i] + a[i+1];
                j++;
            }

            if(n%2==1) {
                n = n/2 + 1;
            }else n = n/2;
            a[n+1] = 0;
            int temp = 0;
            for(int i=1; i<=n; i++){
                if(temp<a[i]){
                    temp = a[i];
                }
            }
            sum+=temp;
        }
        cout << sum;
    }

    return 0;
}
