#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100001

int a[MAX_N], s[MAX_N];
int n,res = 0;

void incsubseq() {
    s[1] = 1;
    res = s[1];
    for(int i = 2; i <= n; i++) {
        s[i] = 1;
        for(int j = 1; j <= i-1; j++) {
            if(a[j] == a[i] - 1) {
                if(s[i] < s[j] + 1)
                    s[i] = s[j] + 1;
            }
        }
        if(s[i] > res) {
            res = s[i];
        }
    }

    cout << res;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
    }

    incsubseq();

    return 0;
}
