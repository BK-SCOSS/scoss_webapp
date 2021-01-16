#include <bits/stdc++.h>
using namespace std;

int a[107];
int b[107];

int main()
{

    int n;
    cin >> n;
    vector<int> res;
    while(n--)
    {
        // res.clear();
        int k, h;
        cin >> k;
        a[k];
        for(int i = 0; i < k; i++){
            cin >> a[i];
        }
        sort(a, a+k);
        cin >> h;
        b[h];
        for (int i = 0; i < h; i++){
            cin >> b[i];
        }
        sort(b, b+h);

        int x = 0, y = 0, cnt = 0;
        while(x < k && y < h)
        {
            if(a[x] == b[y]) {cnt++;x++; y++;}
            else if(a[x] > b[y]) y++;
            else if(a[x] < b[y]) x++;
        }
        cout << cnt << endl;
    }
    
}