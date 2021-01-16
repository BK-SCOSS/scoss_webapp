#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100001
int n, max_re, re;
int a[MAX_N];

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << a[1] << endl;
        }
        int nb = n;

        while(true){
            if(nb%2 == 0){
                for(int i = 1; i <= nb; i ++){
                    a[i] = a[i*2-1] + a[i*2];
                }

                for(int i = 1; i <= nb; i++){
                    max_re = max(max_re, a[i]);
                }
            }

            if(nb%2 == 1){
                for(int i = 1; i <= nb; i++){
                    a[i] = a[i*2-1] + a[i*2];
                }

                for(int i = 1; i <= nb+1; i++){
                    max_re = max(max_re, a[i]);
                }
            }

            if(nb == 0){
                break;
            }

            //cout <<"max_re = " << max_re << endl;
            re += max_re;
            //cout << "re = " << re << endl;
            nb /= 2;
        }

        cout << re;

    }
}
