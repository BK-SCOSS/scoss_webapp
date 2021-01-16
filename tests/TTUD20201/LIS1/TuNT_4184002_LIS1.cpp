#include <bits/stdc++.h>
using namespace std;

const int Max = 100005;
int t, n, k, a[Max];
unsigned int res = 1;
int c[Max][3];
int flag = 0;

void check(int a[], int n) {
    k = 1;
    c[0][0] = a[0];
    c[0][1] = 1;
    for(int i = 1; i < n; i++) {
        c[i][1] = 0;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(a[i] == (c[j][0]+1)) {
                c[j][0] = a[i];
                c[j][1] ++;
            } else {
                c[k][0] = a[i];
                c[k][1] = 1;
                flag = 1;
            }
        }
        if(flag == 1) {
            k++;
            flag = 0;
        }
    }
    for(int i = 0; i < n; i++)
        res = res > c[i][1] ? res : c[i][1];
    cout << res << endl;
}

int main()
{
    cin >> t;
    for(int x = 0; x < t; x++) {
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j];
        check(a, n);
    }
    return 0;
}
