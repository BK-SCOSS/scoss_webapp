#include <bits/stdc++.h>

using namespace std;
long long souoccuaT(int n) {
     int a=0,b=0,c=0;
     for(int i=1;i <= sqrt(n+1);i++) {
            if ((n+1)%i == 0 && (n+1)/i != i) b+= 2;
            if ((n+1)%i == 0 && (n+1)/i == i) b+= 1;}
     if(n%2 != 0) {
            for(int i=1;i <= sqrt(n);i++) {
            if (n%i == 0 && n/i != i) a+= 2;
            if (n%i == 0 && n/i == i) a+= 1;}
            for(int i=1;i <= sqrt(n+2);i++) {
            if ((n+2)%i == 0 && (n+2)/i != i) c+= 2;
            if ((n+2)%i == 0 && (n+2)/i == i) c+= 1;}
            return a*b*c-1;}
     if (n%2 == 0) {
        int x=n, y=n+2;
        int d=0;
        while (x%2 ==0){
            d++;
            x /= 2;
        }
        while (y%2 ==0) {d++; y/=2;}
        for(int i=1;i <= sqrt(x);i++) {
            if (x%i == 0 && x/i != i) a+= 2;
            if (x%i == 0 && x/i == i) a+= 1;}
            for(int i=1;i <= sqrt(y);i++) {
            if (y%i == 0 && y/i != i) c+= 2;
            if (y%i == 0 && y/i == i) c+= 1;}
            return a*b*c*(d+1)-1;}


     }
 long long souoccuaT2 (int n) { int a=1,b=1,c=1,d=0;
     for (int i=1;i<n+1;i++) if((n+1)*(n+1) %i==0) a+=2;
     int x=n,y=n+2;
     while (x%2 ==0){
            d++;
            x /= 2;
        }
        while (y%2 ==0) {d++; y/=2;}
        for (int i=1;i<x;i++) if(x*x %i==0) b+=2;
        for (int i=1;i<y;i++) if(y*y %i==0) c+=2;


     return a*b*c*(2*d+1);

 }

int main()
{ int n;
cin >> n;
unsigned int a[n];
for(int i=0;i<n;i++) cin >> a[i];

for(int i=0;i<n;i++) cout << (souoccuaT2(a[i]) -1 - 2*souoccuaT(a[i]))/2 << endl;


return 0;
}
