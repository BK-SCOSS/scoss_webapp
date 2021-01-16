//
//  main.cpp
//  CuoiKi.A
//
//  Created by Lê Tường Khanh on 16/01/2021.
//

#include <iostream>
using namespace std;

int t,m,n,dem;
long a[100];
long b[100];

int main(int argc, const char * argv[]) {
    cin >>t;
    for(int i=0;i<t;i++){
        dem =0;
        cin >> n;
        for(int j =0;j<n;j++){
            cin >>a[j];
        }
        cin >> m;
        for(int j =0;j<m;j++){
            cin >>b[j];
        }
        for(int j =0;j<n;j++){
            for(int k =0;k<m;k++){
                if (a[j] == b[k]) dem++;
            }
        }
        cout <<dem << endl;
    }
    return 0;
}
