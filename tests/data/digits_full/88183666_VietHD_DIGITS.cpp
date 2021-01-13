#include <bits/stdc++.h>
using namespace std;
int t, n, res=0;
int a[10], mark[10];
int check()
{
    int hust = a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4];
    int soict = a[3] * 10000 + a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[4];
    return hust + soict;
}
void process(int k)
{
    if (k>7){
        int sum = check();
        if (sum==n) {
            res++;
            // for (int i = 1; i <=7; i++)
            // {
            //     cout << a[i] << " " ;
            // }
            // cout << endl;

        }
        return;
    }
    for (int i=0; i<=9; ++i){
        if (i==0 && (k==1 || k==3))
            continue;
        if (!mark[i]){
            mark[i] = 1;
            a[k] = i;
            process(k+1);
            mark[i] = 0;
        }
    }
}
int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        res = 0;
        memset(a, 0, sizeof(a));
        memset(mark, 0, sizeof(mark));
        process(1);
        cout << res << endl;
    }

    return 0;
}