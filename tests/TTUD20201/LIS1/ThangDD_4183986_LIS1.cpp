#include <bits/stdc++.h>

using namespace std;

int A[1000000];
int n;
vector <int> P;

void TRY(int k){
    for(int i = k+1; i<n; i++){
        if(A[i]==A[k]+1){
            P.push_back(A[i]);
            if(i==n-1) {
                for(int bien : P){
                    cout << P.at(bien);
                }
                cout << endl;
            }
            else TRY(i);
        }
    }
    P.pop_back();
}



int main(){
    int T, len=0;
    cin >> T;

    int dem=0;
    while(T--){
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> A[i];
        }
        for(int j = 0; j<n; j++){
            P.push_back(A[j]);
            TRY(j);
            P.clear();
        }
    }
    cout << dem+1;
}


