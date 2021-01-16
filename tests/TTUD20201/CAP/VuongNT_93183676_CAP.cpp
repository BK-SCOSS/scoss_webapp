#include<bits/stdc++.h>
using namespace std;
int mang[10000000];
int main(){
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        int A[k]; 
        for(int i = 0; i < k ; i++){
            cin >> A[i];
        }
        int k2;
        cin >> k2;
        int B[k2];
        
        for(int i = 0; i < k2; i++){
            cin >> B[i];
        }
        sort(A, A+k);
        sort(B, B+k2);
        vector<int> result;
        set_intersection(A, A+k, B, B+k2,inserter(result, end(result)));


        cout << result.size() << endl;

    }
}