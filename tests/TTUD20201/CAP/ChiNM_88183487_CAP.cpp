//
//  main.cpp
//  THUATTOANUNGDUNG_CUOIKI
//
//  Created by Matt on 1/16/21.
//

#include <iostream>
using namespace std;

int N;
int n[10];
int m[10];
int results[10];

void Try(){
    
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin>> n[i];
        int a[n[i]];
        for (int j = 0; j < n[i]; j++) {
            cin >> a[j];
        }
        cin>> m[i];
        int b[m[i]];
        for (int j = 0; j < m[i]; j++){
            cin >> b[j];
        }
        
        int checked[m[i]];
        for (int j = 0; j < m[i]; j ++) {
            checked[j] = 0;
        }
        
        int result = 0;
        for (int j = 0; j < n[i]; j++) {
            for (int z = 0; z < m[i] ; z++) {
                if(checked[z] == 0){
                    if(a[j] == b[z]){
                        result ++;
                        checked[z] = 1;
                    }
                }
            }
        }
        
        results[i] = result;
        
    }
    
    for (int i = 0; i < N ; i++) {
        cout << results[i] << endl;
    }
    
    return 0;
}
