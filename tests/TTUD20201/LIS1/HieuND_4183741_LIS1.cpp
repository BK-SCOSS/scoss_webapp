#include<bits/stdc++.h>

using namespace std;
#define MAX 1001

int n;
int a[MAX];
int res = 1;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) 
    {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if(a[i+j] == a[i] + 1)
                    res++;
            }
        }
        cout << res;
    }
    return 0;
}