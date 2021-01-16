#include<bits/stdc++.h>
using namespace std;
int codeCap() {
    int n;
    cin >> n;
    int arrN[n];
    int countDep = 0;
    for (int i = 0; i < n; i ++) {
        cin >> arrN[i];
    }

    int newArr[n];
    int index = 0;

    for (int i = 0;i < n; i ++) {\
        bool checkCut = true;
        for (int j = i+1; i < n; i ++) {
            if(arrN[j] > arrN[i]) {
                checkCut = false;
            }
        }
        if (checkCut == false) {
            newArr[index] = arrN[i];
            index++;
        }
    }
    int maxSum = 0;
    for (int i = 0; i < n; i ++) {
        int sum = 1;
        int currentValue = arrN[i];
        for (int j = i+1; j< n;j++) {
            if (arrN[j]-currentValue == 1) {
                currentValue = arrN[j];
                sum += 1;
            }
        }
        if (maxSum < sum) {
            maxSum = sum;
        }
    }

    return maxSum;
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
