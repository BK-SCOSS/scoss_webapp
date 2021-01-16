#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int T;
int n;
int a[MAX];
int tmp[MAX];

int lis1(int k) {
    if(tmp[k] != -1) return tmp[k];
    
	int temp = 1;
    for(int i=0; i<=k; i++) {
        if(a[k] == a[i] + 1)
            temp = max(temp, 1 + lis1(i));
    }
    tmp[k] = temp;
    return temp;
}

int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        for(int i = 0; i < MAX; i++) {
            a[i] = 0; tmp[i] = -1;
        }
        int rs = 1;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            rs = max(rs, lis1(i));
        }
        cout << rs << endl;
    }
}
