#include <bits/stdc++.h>
using namespace std;

#define ll long long 
ll n;
#define MAX 100009
// int A[MAX];
ll B[MAX];
ll testcase;

ll max_gop_nhom(int number){
    ll max_value = INT_MIN;
    for(int i = 1; i <= number/2; i ++){
        B[i] = B[(i-1)*2 + 1] + B[(i-1)*2 + 2];
        if (B[i] > max_value) max_value = B[i];
    }
    return max_value;
}

int main(){
    cin >> testcase;
    while(testcase--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> B[i];
        }
        ll number = n;
        ll count_value = 0;
        while(number > 1){
            if (number % 2 == 0){
                ll max_value = max_gop_nhom(number);
                count_value += max_value;
                number = number/2;
                
            }
            else{
                ll max_value = max_gop_nhom(number-1);
                count_value += max_value;
                B[(number-1)/2 + 1] = B[number];
                number = (number-1)/2 + 1;
            }
        }
        cout << count_value << endl;

    }

}