#include <iostream>
#include <bits/stdc++.h>
#define MAX 100
using namespace std;

long long a[MAX];
long long b[MAX];
int test;
int n, m;
int _count=0;

void input(long long *a,int n){
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

int solve(long long *a, long long *b, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i]==b[j] && a[i]!=0){
                _count++;
                a[i] = 0;
                b[i] = 0;
            }
        }
    }
    return _count;
}

int main()
{
    cin >> test;
    while(test >0){
        cin >> n;
        input(a, n);
        cin >> m;
        input(b, m);

        cout << solve(a, b, n, m);
        test--;
    }
    return 0;
}
