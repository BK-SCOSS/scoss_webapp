#include<bits/stdc++.h>
using namespace std;


// so nhom
int num;
// so nguoi moi nhom
vector<int>B (100000, 0);
unsigned long long max_T;
unsigned long long curmax = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Test;
    cin >> Test;
    for(int x = 0; x < Test; x++){
        max_T = 0;
        cin >> num;
        for(int i = 1; i <= num ; i++){
            cin >> B[i];
        }
        while(num > 1){
            curmax = 0;
            if(num % 2 == 0){
                for(int i = 1; i <= num; i+=2){
                    //cout << B[i] << " " << B[i+1] << " ";
                    if(B[i] + B[i+1] > curmax) curmax = B[i] + B[i+1];
                    B[(i+1)/2] = B[i] + B[i+1];
                }
                //cout << endl;
                max_T += curmax;
                num = num/2;
            }
            else{
                for(int i = 1; i <= num-1; i+=2){
                   // cout << B[i] << " " << B[i+1] << " ";
                    if(B[i] + B[i+1] > curmax) curmax = B[i] + B[i+1];
                    B[(i+1)/2] = B[i] + B[i+1];
                    //cout << curmax << endl;
                }
                //cout << endl;
                B[num/2 + 1] = B[num];
                max_T += curmax;
                num = num/2 + 1;            
            }
            //cout << max_T << endl;
            //cout << curmax << endl;
        }
        cout << max_T << endl;
    }
    return 0;
}