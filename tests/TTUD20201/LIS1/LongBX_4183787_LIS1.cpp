#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int nxt[1000];
int dump[1000];
int rslt[1000];

int lis(int a[], int n) {
    int r = 0, i, j;
    for (i = 1; i <= n; i++)
        if (r == 0 || a[i] == a[dump[r]]+1) {
            nxt[i] = (r == 0 ? 0 : dump[r]);
            dump[++r] = i;
        } else {
            int ll = 1, rr = r, j = (ll + rr) / 2;
            while (ll != j && j != rr) {
                if (a[i]+1 <= a[dump[j]])
                    rr = j;
                else
                    ll = j;
                j = (ll + rr) / 2;
            }
            for (j = ll; j <= rr; j++) {
                if (a[i]+1 <= a[dump[j]]) {
                    nxt[i] = dump[j - 1];
                    dump[j] = i;
                    break;
                }
            }
        }

    j = r;
    for (i = dump[r]; i != 0; i = nxt[i]) rslt[j--] = i;
    return r;
}


int a[1000];

int main() {
    
    int T,n[100],ans[100];
    cin>>T;
    for (int j=1; j<=T; j++)
    {
    cin>>n[j];
    for (int i = 1; i <= n[j]; i++) {
	cin>>a[i];}

    ans[j] = lis(a, n[j]);
    for (int i = 1; i <= n[j]; i++)
    a[i]=0;
    }
    for (int j=1; j<=T; j++)
    cout<<ans[j]<<endl;
}
