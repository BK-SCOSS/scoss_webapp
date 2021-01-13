#include <bits/stdc++.h>

using namespace std;
int t, x[10],flag[10],num = 0;
long long n;
long long cal() {
    return 1000*x[1]+ 100*x[2]+10010*x[3]+2*x[4]+1000*x[5]+100*x[6]+10*x[7];
}

void digit(int i) {
    for (int j = 0; j<10;j++) {
        if (!flag[j]) {
            if (i == 1 && j == 0 || i==3 && j == 0)
                continue;
            x[i] = j;
            flag[j] = 1;
            if (i == 7) {
                if (cal() == n) {
                    num++;
                }
            }
            else
                digit(i+1);
            flag[j] = 0;
        }
    }
}



int main() {
  //  freopen("D:\\CodeBlock\\KTRA\\Bai1\\input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        num = 0;
        memset(x,0,sizeof(x));
        memset(flag,0,sizeof(flag));
        digit(1);
        cout << num << endl;
    }
    return 0;
}
