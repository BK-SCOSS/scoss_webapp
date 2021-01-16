#include<bits/stdc++.h>

using namespace std;
int n;
int a[100001];
int t[20][100001];
int find_exp(int x) {
    int e = 0;
    while(pow(2, e) < x) {
        e++;
    }
    return e;
}

int main() {
    int rep;
    cin >> rep;
    while(rep--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int m = find_exp(n);
        int max_elem = n, prev;
        for(int i = 1; i <= n; i++) {
            t[0][i] = a[i];
        }
        int time = 0, cur_max = 0;
        for(int i = 1; i <= m; i++) {
            cur_max = 0;
            prev = max_elem;
            max_elem = (max_elem%2 + max_elem/2);
            //cout << "max elem = " << max_elem << endl;
            for(int j = 1; j <= max_elem; j++) {
                if(2*j <= prev)
                    t[i][j] = t[i-1][2*j - 1] + t[i-1][2*j];
                else t[i][j] = t[i-1][2*j - 1];
                //cout << "t[" << i << "][" << j << "] = " << t[i][j] << endl;
                cur_max = max(cur_max, t[i][j]);
            }
            //cout << "cur_max = " << cur_max << endl;
            time += cur_max;
        }
        cout << time;
    }
}
