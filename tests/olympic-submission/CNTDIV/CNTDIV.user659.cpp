#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;
vector <int> so;

long long n, a[10000], nt[1000000], kq[1000000];


int main(){
   
    cin >> n;
    long long x, y, z;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        y = x * (x+ 1)*(x+ 2);
        z = y * y;
        for(int j = 1; j <= y; j++){
            if(z % j == 0 && j < y && y % j != 0 ){
                kq[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << kq[i] << "\n";
    }
}