#include <bits/stdc++.h>

using namespace std;

bool check(int t, int A[]) {
    for (int i = 0; i < 7; i++)
        if (A[i] == t)
            return false;
    return true;
}

int solve(int n) {
    int A[7]; // S, H, O, U, I, C, T
    int s = 0; 
    if(n % 2 == 1)
        return 0;
    A[6] = (n % 10) / 2;
    n = n - A[6]*2;
    A[5] = (n % 100) / 10;
    if(A[6] == A[5])
        return 0;
    n = n - A[5]*10;
    for(int o = 0; o < 10; o++) {
        A[0] = o;
        for(int j = 0; j < 10; j++) {
            A[1] = j;
            for(int k = 0; k < 10; k++) {
                A[2] = k;
                for(int m = 0; m < 10; m++) {
                    A[3] = m;
                    for (int q = 0; q < 10; q++) {
                        A[4] = q;
                        if(check(0, A) && check(j, A) && check(k, A) && check(m, A) && check(q, A))
                            if((o*10010 + j*1000 + k*1000 + m*100 + q*100) == n)
                                s++;
                    }
                }
            }
        }
    }
    return s;
}

int main() {

    int T;
    cin >> T;
    int ds[50], kq[50];
    for(int i = 0; i < T; i++) {
        cin >> ds[i];
    }
    for(int i = 0; i < T; i++) {
        kq[i] = solve(ds[i]);
    }
    for(int i = 0; i < T; i++) {
        cout << kq[i] << endl;
    }

    


    
    return 0;
}
