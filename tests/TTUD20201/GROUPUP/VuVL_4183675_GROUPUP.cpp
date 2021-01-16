//
// Created by Zbook 15 G3 on 1/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int a[100009];

int n;
int timMax(int so_nhan){
    int currMax = 0;
    int chay = 1;
    while(chay < n) {
        int crr = 0;

        for (int j = 0; j < so_nhan; j++) {
            crr += a[chay + j];
        }

        currMax = max(currMax, crr);
        chay += so_nhan;
    }

    return currMax;
}
int main() {
    int T;

    cin >> T;
    while (T--) {

        cin >> n;
        for (int i = 1; i <=n; i++) {
            cin >> a[i];
        }


        int maxS = 0;
        int so_nhan = 2;
        for(int i = 1; i <= n / 2; i++) {

            if(n / so_nhan != 0) {
                maxS += timMax((int)so_nhan);

            } else {
                for(int k = 1; k <= n; k++) maxS += a[k];
                cout << maxS;
                break;
            }
            so_nhan = so_nhan * 2;

        }


    }
    return 0;
}