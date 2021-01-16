#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T,n,m;
unsigned long long int a[100000];


int main() {
    cin >> T;
    while(T--) {
        if (n>0)
            {for (int i=0; i<n ; i++) {
                a[i] = 0;
            }}
        cin >> n;
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
    
        int count = 1;
        if (n>m) {
            for (int j=0; j<n-1; j++){
                int i = j;
                int c = 1;
                int key = a[i];
                i++;
                while(i<n) {
                    if (a[i] == key+1) {
                        key = a[i];
                        i++;
                        c++;
                        // cout << i;
                    } else {
                        i++;
                    }
                } 
                if (c > count) count=c;
            }
            
        }
        cout << count <<endl;
    }
    return 0;
}
