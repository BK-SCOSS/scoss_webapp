//
// Created by Hoang Nam on 10/16/2020.
//

#include <bits/stdc++.h>
typedef unsigned long long ull;

using namespace std;
ull T;
ull T_square;
int main()
{
    int t;
    cin >> t;
    while(t-- > 0)
    {
        ull cnt = 0;
        int n;
        cin >> n;
        T = n * (n + 1) * (n + 2);
        T_square = T * T;
        for(int i = 2; i <= sqrt(T); i++)
        {
            if(T % i != 0 && T_square % i == 0)
                cnt++;
        }
        for(int i = sqrt(T) + 1; i < T; i++)
        {
            if(T % i != 0 && T_square % i == 0)
                cnt++;
        }
        cout << cnt << endl;
    }
}