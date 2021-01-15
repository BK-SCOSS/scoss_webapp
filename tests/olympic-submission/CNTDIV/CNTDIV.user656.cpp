#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        long long n;
        scanf("%lld", &n);
        unsigned long long t = n*(n+1)*(n+2);
        unsigned long long t2 = t*t;
        int d = 0;
        //cout << t2 << " ";
        for (unsigned long long i = t - 1; i >= 4; i--){
            if (t2 % i == 0 && t%i != 0){
                //cout << i << " ";
                d++;
            }
        }
        cout << d << "\n";
    }
}
