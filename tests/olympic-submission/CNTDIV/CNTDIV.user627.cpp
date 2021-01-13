#include <bits/stdc++.h>

using namespace std;

int US(unsigned long long n, unsigned long long t){
    int countRes = 0;
    for(int i = 2; i * i < t; i++){
        if(t % i == 0 && n % i != 0) countRes++;
    }
    return countRes;
}
int main(){
    int q;
    cin >> q;
    unsigned long long t;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        unsigned long long tmp;
        tmp = x * (x + 1) * (x + 2);
        t = tmp * tmp;
        cout << US(tmp, t) << endl;
    }
    
}