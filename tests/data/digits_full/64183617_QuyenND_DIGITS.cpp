#include<bits/stdc++.h>
using namespace std;

// number of test cases
int N;
// HUST + SOICT = key
int key;
/*
    H = Ans[0]
    U = Ans[1]
    S = Ans[2]
    T = Ans[3]
    O = Ans[4]
    I = Ans[5]
    C = Ans[6]
*/
int Ans[10];
int check[10];
int Count = 0;

int calculate(){
    return Ans[0]*1000 + Ans[1]*100 + Ans[2]*10010 + Ans[3]*2 + Ans[4]*1000 + Ans[5]*100 + Ans[6]*10; 
}

bool UCV(int k, int i){
    if(k == 0 || k == 2){
        if(i == 0) return false;
    }
    if(check[i] == 0) return true;
    return false;
}

void Try(int k){
    for(int i = 0; i < 10; i++){
        if(UCV(k, i)){
            Ans[k] = i; 
            check[i] = 1;
            if(k == 6 && calculate() == key) Count++;
            else{
                Try(k+1);
            }
            check[i] = 0;
            Ans[k] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i<N; i++){
        Count = 0;
        //Ans[0] = 0;    
        //Ans[1] = 0;
        //Ans[2] = 0;
        //Ans[3] = 0;
        //Ans[4] = 0;
        //Ans[5] = 0;
        //Ans[6] = 0;
        cin >> key;
        if(key > 110000){
            cout << Count << endl;
            continue;
        }
        Try(0);
        cout << Count << endl;
    }
    return 0;
}