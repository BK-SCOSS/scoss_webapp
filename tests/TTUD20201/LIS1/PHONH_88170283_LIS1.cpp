#include <bits/stdc++.h>
using namespace std;
int main() {
    int test; cin >> test;
    for (int t = 0; t < test; t++)
    {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        int dep = INT_MIN;
        for (int i = 1; i < n-1; i++)
        {
            if (arr[i-1] < arr[i+1]) dep = arr[i];
        }
        
        cout << dep << endl;
    }
    
}
