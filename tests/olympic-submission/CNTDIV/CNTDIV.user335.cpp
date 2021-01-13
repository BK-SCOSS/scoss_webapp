#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int d; cin>>d;
    for (int i=1; i<=d; i++) {
        int n,kq=0; cin>>n;
        long long t=n*(n+1)*(n+2);
        for (int j=1; j<=t; j++)
            if ( t*t%j==0 && t%j!=0 ) kq++;
        cout<<kq<<endl;
    }
}
