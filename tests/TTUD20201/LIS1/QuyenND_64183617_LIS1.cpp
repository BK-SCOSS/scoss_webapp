#include<bits/stdc++.h>
using namespace std;

// day de bai cho
int lis[100000];
// so phan tu
int num;
// luu lai cac day con cu
int dp[100000];
// max
int best = 1;

void lis1(){
    dp[0] = 1;
    for(int i = 1; i < num ; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(lis[i] == lis[j] + 1){
                dp[i] = dp[j] + 1;
                break;
            }
        }
        if(dp[i] > best) best = dp[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Test;
    cin >> Test;
    for(int x = 0; x< Test; x++){
        best = 0;
        cin >> num;
        for(int i = 0; i < num; i++){
            cin >> lis[i];
        }
        lis1();
        cout << best << endl;
    }
    return 0;
}