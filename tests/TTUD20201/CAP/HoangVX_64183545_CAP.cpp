#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    int T,n,m;
    int a[100];
    int b[100];
    int status2[100];
    cin>> T;
    while(T>0){
        T--;
        memset(status2,0,sizeof(status2));
        cin>> n;
        for(int i=0;i<n;i++){
            cin>> a[i];
        }
        cin>> m;
        for(int i=0;i<m;i++){
            cin>> b[i];
        }
        int counter = 0;
        for(int i=0;i<n;i++){
            int u = a[i];
            for(int j=0;j<m;j++){
                //cout<< a[i]<<" "<< b[j]<< endl;
                if(u == b[j]&&status2[j]==0){
                    status2[j] = 1;
                    counter++;
                    break;
                }
            }
        }
        cout<< counter<< endl;
    }
    return 0;
}
/*
2
4
2 1 4 3
3
1 5 4
4
2 1 4 3
3
1 5 4
*/
