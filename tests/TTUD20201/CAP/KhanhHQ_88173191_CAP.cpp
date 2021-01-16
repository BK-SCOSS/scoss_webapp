#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    int* n = new int[T];
    int* m = new int[T];
    int**p = new int*[T];
    int**q = new int*[T];
    int *d_a = new int[T];
    for(int i = 0; i < T; i++){
        d_a[i] = 0;
    }
    for(int i = 0; i < T; i++){
        cin >> n[i];
        p[i] = new int[n[i]];
        for(int j = 0; j < n[i]; j++){
            cin>>p[i][j];
        }
        cin >> m[i];
        q[i] = new int[m[i]];
        for(int k = 0; k < m[i]; k++){
            cin>>q[i][k];
            for(int f = 0; f < n[i]; f++){
                if(q[i][k] == p[i][f]){
                    d_a[i]++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < T; i++){
        cout<<d_a[i]<<endl;
    }
    return 0;
}