#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long a,b,a1,b1,a2,b2;
    int n;
    cin >> n;
    while(n--){
    cin >> a >> b;
    a1=a%10;
    b1=b%10;
    a2=a/10;
    b2=b/10;
    if (a2+b2==0 && a1+b1<10){
        cout << a1+b1;
    }else if (a1+b1<10){
        cout << a2+b2 << a1+b1 << "\n";
    }else{
        cout << a2+b2+1 << a1+b1-10 << "\n";;
    }
    }
}
