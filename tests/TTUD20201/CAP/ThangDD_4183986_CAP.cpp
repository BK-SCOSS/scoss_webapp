#include <iostream>

using namespace std;

int A[1000], B[1000];

int main(){
    int T;
    cin >> T;
    int dem = 0;

    int n, m;
    while(T--){
       cin >> n;
       for(int i = 0; i<n; i++){
            cin >> A[i];
       }
       cin >> m;
       for(int j = 0; j<m; j++){
            cin >> B[j];
       }
       for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(A[i]==B[j]){
                    dem++;
                }
            }
       }
       cout << dem << endl;
    }
}
