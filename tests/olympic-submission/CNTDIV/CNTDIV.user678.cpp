#include <bits/stdc++.h>
using namespace std;
int q,n;

unsigned long long s1,s2;
int main() {
    cin >>q;
    for(int i=0; i<q; i++) {
        int cnt =0;
        cin>>n;
        s1= n*(n+1) *(n+2);
        s2= n*(n+1) *(n+2)*n*(n+1) *(n+2);
        for(int j=3; j<= s1;j++) {
            if(s2%j ==0 && s1%j!=0){
                cnt ++;
            }
        }
        cout <<cnt <<endl;
    }
    return 0;
}
