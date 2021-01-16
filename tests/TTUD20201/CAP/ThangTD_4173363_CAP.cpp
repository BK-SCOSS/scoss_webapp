#include<bits/stdc++.h>
using namespace std;
int codeCap() {
    int n;
    cin >> n;
    int arrN[n];
    for (int i = 0; i < n; i ++) {
        cin >> arrN[i];
    }


    int m;
    cin >> m;
    int arrM[m];
    int countGiao = 0;
    //int giao[m];
    for (int i = 0; i < m; i ++) {
        cin >> arrM[i];
        for (int j = 0; j < n; j++) {
            if (arrM[i] == arrN[j]) {
                //giao[i] = arrM[i];
                countGiao += 1;

                break;
            }
        }
    }
    //sort(giao, 1);
    //for (int i = 0; i < n; i ++) {
    //    if (giao[i] != giao[i+1]) {
    //        countGiao += 1;
    //    }
   // }
    return countGiao;
}

int main() {
    int test;
    cin >> test;
    int s[test+1];
    for (int i = 0; i < test; i ++) {
        s[i] = codeCap();
    }
    for(int i = 0; i < test; i ++) {
        cout << s[i] << '\n';
    }
}
