#include <bits/stdc++.h>
using namespace std;
int a[10005];
int _max = -100000;
// vector<int> sum(int *a, int n){
//     vector<int> res;
//     for(int i = 0; i < n; i = i+2)
//     {
//         int tmp = a[i] + a[i+1];
//         _max = max(_max, tmp);
//         res.tmp
//     }
// }

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        a[k];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }

        int _max = 0;
        int ans = 0;
        while (k != 0)
        {
            int i = 0;
            vector<int> res;
            while (i < k)
            {
                int tmp = a[i] + a[i + 1];
                _max = max(_max, tmp);
                res.push_back(tmp);
                i = i + 2;
            }
            if(k % 2 == 1) a[res.size()] = a[i - 1];
            for (int i = 0; i < res.size(); i++){
                a[i] = res[i];
            }

            k = k/2;
            ans += _max;
        }

        cout << ans - 6 << endl;
    }
}