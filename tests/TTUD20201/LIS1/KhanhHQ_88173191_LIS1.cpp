#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    int* n = new int[T];
    int**p = new int*[T];
    int**q = new int*[T];
    int* d_a = new int[T];
    for(int i = 0; i < T; i++){
        d_a[i] = 0;
    }
    for(int i = 0; i < T; i++){
        cin >> n[i];
        p[i] = new int[n[i]];
        q[i] = new int[n[i]];
        for(int d = 0; d < n[i]; d++){
            q[i][d] = 1;
        }
        for(int j = 0; j < n[i]; j++){
            cin >> p[i][j];
            for(int k = j ; k >= 0; k --){
                if(p[i][j] - p[i][k] == 1){
                    q[i][j] = q[i][k] + 1;
                    break;
                }
            }
        }
        int a = q[i][0];
        for(int z = 0; z < n[i]; z++){
            if(q[i][z] > a){
                a = q[i][z];
            }
        }
        d_a[i] = a;
    }

    for(int i = 0; i < T; i ++){
        cout<< d_a[i]<<endl;
    }

return 0;
}