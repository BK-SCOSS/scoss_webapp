#include <iostream>
#include <stack>
#include <queue>
int t;
const int l_num = 7;
int count = 0;
int sum = 0;

void trace(int k, int *a, int n, int* pow10, int* isin){
    if(k > l_num - 1) {
        if(sum + a[2] * pow10[4] == n) {
            count++;
        }
        return;
    }
    for(int i = 0; i < 10; i++) {
        if((k == 5 || k == 2) && i == 0) continue;
        if(isin[i]) {
            sum += i * (pow10[(k + 1) / 2]);
            a[k] = i;
            isin[i] = 0;
            trace(k + 1, a, n, pow10, isin);
            sum -= i * (pow10[(k + 1) / 2]);
            isin[i] = 1;
        }
    }
}

int main() {
    std::cin >> t;
    int n[t];
    for(int i = 0; i < t; i++) {
        std::cin >> n[i];
    }
    int a[l_num];
    int isin[10];
    for(int i = 0; i < 10; i++) {
        isin[i] = 1;
    }
    int pow10[] = {2, 10, 100, 1000, 10000};
    for(int i = 0; i < t; i++) {
        trace(0, a, n[i], pow10, isin);
        std::cout << count << "\n";
        count = 0;
    }
}
