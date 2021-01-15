#include<bits/stdc++.h>

using namespace std;
int n,m;

int countDivisors(int n) 
{ 
    int cnt = 0; 
    for (int i = sqrt(n); i <= n; i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
int main(){
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while (q--)
    {
       int n;
       cin>> n ;
    cout<< countDivisors(n);
    }
    
    return 0;
}