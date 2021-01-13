//
//  main.cpp
//  Digits
//
//  Created by Lê Tường Khanh on 28/11/2020.
//

#include <iostream>
#include <vector>
using namespace std;

long n;
long dem;
vector<bool> v(10);
int a[9];
bool check(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9){
    return ((a1+a6)*1000+(a2+a7)*100+(a3+a8)*10+a4+a9+a5*10000 == n) ;
}
void Try(int k){
    if (n <6789+12345 ||n>98765 + 4321) dem =0;
    else if(k==10) {
        if(check(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]))
            dem++;
    }
    else for(int i =0;i<9;i++){
        if (!v[i]) {
            if ((k ==0||k==4) && i){
                v[i] = true;
                a[k] = i;
                Try(k+1);
                a[k] = 0;
                v[i] = false;
            }
            else {
                v[i] = true;
                a[k] = i;
                Try(k+1);
                a[k] = 0;
                v[i] = false;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int t;
    cin>>t;
    dem =0;
    for(int i =0;i<t;i++){
        cin >> n;
        Try(0);
        cout <<dem;
    }
    return 0;
}
