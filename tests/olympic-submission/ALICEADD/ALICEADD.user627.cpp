#include<iostream>
 
using namespace std;
void sol(unsigned long long a, unsigned long long b){
    unsigned long long a0, a1, b0, b1, c0, d;
    int c1, c2;
    a0 = a % 10;
    b0 = b % 10;
    a1 = a / 10;
    b1 = b / 10;
    c0 = a0 + b0;
    c1 = c0 / 10;
    c2 = c0 % 10;
    d = a1 + b1 + c1;
    if(d == 0) cout << c2;
    else
    	cout << d << c2;
}
int main(){
   int t;
   cin >> t;
   unsigned long long a, b;
   for(int i = 0; i < t; i++){
       cin >> a >> b;
       sol(a, b);
       cout << endl;
   }
    
   
    	
}