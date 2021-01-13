#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int arr[7];

void solution(int N) {
    int tmp = 0;
    tmp = arr[0] * 1000 + arr[1] * 100 + arr[2] * (10 + 10000) + arr[3] * 2 + arr[4] * 1000 + arr[5] * 100 + arr[6] * 10;
    if (tmp == N) cnt++;
    return;
}

void go (int step, bool* taken, int N) {
    for (int i = 0; i <= 9; i++) {
        if (!taken[i]) {
            if ((step == 0 || step == 2) && i == 0) continue;
            arr[step] = i;
            taken[i] = true;
            if (step == 6) solution(N);
            else go (step + 1, taken, N);
            arr[step] = -1;
            taken[i] = false;
        }
    }
}

int main() {
    int T, N;
    cin >> T;
    bool taken[10];
    while (T) {
        cnt = 0;
        cin >> N;
        for (int i = 0; i < 10; i++) {
            taken[i] = false;
        }

        for (int i = 0; i < 7; i++) {
            arr[i] = -1;
        }
        //H0 U1 S2 T3 O4 I5 C6
        go(0, taken, N);
        cout << cnt << endl;
        T--;
    }
    return 0;
}
