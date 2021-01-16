#include<bits/stdc++.h>
using namespace std;

int chia(int x){
    return x%2 == 0 ? x/2 : (x+1)/2;
}



void xx(){
    int n;

    cin >> n;
    int a[n], n_ =  n;
    for(int i = 0; i <n; i++) cin >> a[i];


    int dem = 0;
    while (n_ > 1){
        int n_0 = n_, maxx = 0;
        n_ = chia(n_);
        

        for(int i = 0; i < n_; i ++){
            if (n_0 % 2 == 1 && i == n_ - 1)
                 a[i] = a[2*i];
            else a[i] = a[2*i] + a[2*i+1];
            
            maxx = max(a[i], maxx);
        }


        dem += maxx;
        
    }
    cout << dem << endl;
}
int main(){
    
    // freopen("in3.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i <T; i++)
        xx();
    return 0;
}