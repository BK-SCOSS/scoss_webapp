#include <bits/stdc++.h>
using namespace std;

// Bai 1 CAP
int main() {
    int test; cin >> test;
    for (int t = 0; t < test; t++)
    {    
        int n; cin >> n;
        int arrA[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arrA[i];
        }
        int m; cin >> m;
        int arrB[m];
        for (int i = 0; i < m; i++)
        {
            cin >> arrB[i];
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arrA[i] == arrB[j]) count++;
            }
            
        }

        cout << count << endl;    
    }
}
