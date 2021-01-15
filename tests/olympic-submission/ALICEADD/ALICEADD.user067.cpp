#include<bits/stdc++.h>

using namespace std;
unsigned long long a,b;
void add(unsigned long long a,unsigned long long b){
    int c = a%10;
    int d = b%10;
    a = a/10;
    b = b/10;
    if(a+b+(c+d)/10 > 0){
        cout << (a+b+(c+d)/10);
    }
    cout << (c+d)%10 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t > 0){
        cin >> a;
        cin >> b;
        add(a,b);
        t--;
    }

}
