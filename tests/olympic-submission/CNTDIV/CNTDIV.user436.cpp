#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    while(Q--){
        int N;
        cin >> N;
        unsigned long long dem = 0;
        unsigned long long T;
        unsigned long long divisorNumT = 1;
        unsigned long long divisorNumT2  = 1;
        map<int, int> m;
        T = N;
        while(N%2==0){  
            m[2]++;  
            N = N/2;  
        }  
        for (int i = 3; i <= sqrt(N); i = i + 2){  
            while (N % i == 0)  
            {  
                m[i]++;
                N = N/i;  
            }  
        }  
        if(N>2) m[N]++; 
        N = T+1;
        while(N%2==0){  
            m[2]++;  
            N = N/2;  
        }  
        for (int i = 3; i <= sqrt(N); i = i + 2){  
            while (N % i == 0)  
            {  
                m[i]++;
                N = N/i;  
            }  
        }  
        if(N>2) m[N]++;
        N = T+2;
        while(N%2==0){  
            m[2]++;  
            N = N/2;  
        }  
        for (int i = 3; i <= sqrt(N); i = i + 2){  
            while (N % i == 0)  
            {  
                m[i]++;
                N = N/i;  
            }  
        }  
        if(N>2) m[N]++; 
        for(auto x:m){
            divisorNumT *= x.second+1;
            divisorNumT2 *= x.second*2+1;
        }
        cout << (divisorNumT2-divisorNumT*2+1)/2 << endl;
    }
}