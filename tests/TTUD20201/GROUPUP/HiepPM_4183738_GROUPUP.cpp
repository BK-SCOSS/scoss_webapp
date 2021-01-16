#include <bits/stdc++.h>

using namespace std;
int t, n;
int res = 0;


void input(int arr[]){
    for(int i  = 0; i < n; i++){
        cin >> arr[i];
    }
}
int findMax(int arr[], int n){
    int res  = -10000;
    for(int i  = 0; i < n; i++)
    {
        res = max(res, arr[i]);
    }
    return res;
}

void solve(int arr[], int n){
    while(n > 1){
        if(n % 2 == 1){
            arr[n] = 0;
            ++n;
        }
        for(int i  = 0; i < n/2; i++){
            arr[i] = arr[2*i] + arr[2*i+1];
        }
        res += findMax(arr, n/2);
        n/=2;
    }
    cout << res << endl;
}


int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        input(arr);
        solve(arr, n);

        res = 0;
    }
    return 0;

}
