#include<bits/stdc++.h>
using namespace std;

int codeCap() {
    int n;
    cin >> n;
    int arrN[n];
    for (int i = 0; i < n; i ++) {
        cin >> arrN[i];
    }

    int countWhile = n%2 ? n/2+1 : n/2;
    int s = 0;
    int arrSS[countWhile][n];
    for (int i = 0; i <n; i ++) {
        arrSS[0][i] = arrN[i];
    }
    int ass = 0;
    int lengths = n;
    while(s < countWhile) {
        int maD = 0;
        for (int i = 0; i < lengths; i ++) {
            if (i==lengths-1) {
                arrSS[s+1][lengths/2] = arrSS[s][i];
            } else if (i%2==0) {
                if (maD < arrSS[s][i] + arrSS[s][i+1]) {
                    maD = arrSS[s][i] + arrSS[s][i+1];
                }
                arrSS[s+1][i/2] = arrSS[s][i] + arrSS[s][i+1];
            }
        }
        s++;
        lengths = lengths%2 ? lengths/2+1 : lengths/2;
        ass += maD;
        //break;
    }
 //  int countDep = tinh(arrN, n);
    return ass;
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
