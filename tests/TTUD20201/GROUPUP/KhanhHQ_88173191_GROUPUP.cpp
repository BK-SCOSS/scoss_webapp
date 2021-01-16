#include<iostream>
#include<string.h>
using namespace std;
int d_ac;
int max(int* n, int i) {
    int max = n[0];
    for (int j = 1; j < i; j++) {
        if (n[j] > max) {
            max = n[j];
        }
    }
    return max;
}
int a(int* p, int k) {
    if (k == 1) {
        return p[0];
    }
    int z = (k +1) /2;
    int* q = new int[z];
    for (int i = 0; i < k; i++) {
        if (i % 2 != 0) {
            q[i / 2] = p[i] + p[i - 1];
        }
        else if (i % 2 == 0 && i == k - 1) {
            q[i / 2] = p[i];
        }
    }
    //cout << "*" << endl;
    //cout << max(q, z) << endl;
    //cout << "*" << endl;
    d_ac += max(q, z);
   // cout << d_ac << endl;
    return a(q, z);
}
int main() {
    int T;
    cin >> T;
    int* n = new int[T];
    int** p = new int* [T];
    int* d_a = new int[T];
    for (int i = 0; i < T; i++) {
        d_a[i] = 0;
    }
    for (int i = 0; i < T; i++) {
        cin >> n[i];
        p[i] = new int[n[i]];
        for (int j = 0; j < n[i]; j++) {
            cin >> p[i][j];
        }
        a(p[i], n[i]);
        d_a[i] = d_ac;
    }
    for (int i = 0; i < T; i++) {
        cout << d_a[i] << endl;
    }
    return 0;
}