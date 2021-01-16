#include<bits/stdc++.h>
using namespace std;

int A[10000];
int B[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numA; 
    int numB;
    int Test;
    int num;
    cin >> Test;
    for(int x = 0; x < Test; x++){
        num = 0;
        cin >> numA;
        for(int i = 0; i < numA; i++){
            cin >> A[i];
        }
        cin >> numB;
        for(int i = 0; i < numB; i++){
            cin >> B[i];
        }
        for(int i = 0; i < numB; i++){
            for(int j = 0; j < numA; j++){
                if(A[j] == B[i]){
                    num++;
                    break;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}