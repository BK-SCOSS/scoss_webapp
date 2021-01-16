#include <bits/stdc++.h>
using namespace std;

const int N=1000000;
int a[N];
int n;
int T;

int lis( int arr[], int n ) {
    int lis[n];
    lis[0] = 1;
    for (int i=1;i<n;i++){
        lis[i] = 1;
        for (int j=0;j<i;j++)
            if ( a[i] > a[j] && lis[i] < lis[j] + 1 && a[i] == a[j]+1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis+n);
}

int main() {
    cin >> T;
    int x[T];
    for(int k=1;k<=T;k++){
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << lis(a, n);
    }
    return 0;
}
