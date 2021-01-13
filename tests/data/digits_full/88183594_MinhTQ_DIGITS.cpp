#include <bits/stdc++.h>

using namespace std;
int a[10];
int n;
int mark[10];
int ans;
void Try(int k) {
    if(k == 7) {
        if(1000*a[0]+100*a[1]+10*a[2]+a[3]+10000*a[2]+1000*a[4]+100*a[5]+10*a[6]+a[3] == n)
            ans++;
    }
    else {
        if(k == 0 || k == 2) {
            for(int i = 1; i < 10; ++i) {
                if(mark[i] == 0)  {
                    mark[i] = 1;
                    a[k] = i;
                    Try(k+1);
                    mark[i] = 0;
                }
            }
        }
        else {
            for(int i = 0; i < 10; ++i) {
                if(mark[i] == 0)  {
                    mark[i] = 1;
                    a[k] = i;
                    Try(k+1);
                    mark[i] = 0;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        for(int i = 0; i < 10; ++i)
            mark[i] = 0;
        Try(0);
        cout << ans << "\n";
    }
}
