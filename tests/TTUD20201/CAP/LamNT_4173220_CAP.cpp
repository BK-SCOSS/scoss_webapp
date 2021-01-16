#include <bits/stdc++.h>
using namespace std;
int t, n, m, countd, temp;
unsigned long long a[1000], b[1000], c[1000];
int main() {    
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        countd = 0;
        for(int j = 0; j < n; j++) {
            cin >> a[j];
            temp = 0;
            if (countd > 0) {
                for(int k = 0; k<countd; k++ ){
                    if ( a[j] == c[k]){ temp = 1;}
                };
                if (temp == 0){c[countd]=a[j]; countd+=1;}
            } else {
                c[countd] = a[j]; 
                countd+=1;
            };
        };
        cin >> m;
        temp = 0;
        for(int j = 0; j < m; j++) {
            cin >> b[j];
            for (int k = 0; k < countd; k++) {
                if (b[j] == c[k]) {temp+=1; c[k]=0;}
            };
        };
        cout << temp << endl;
    };  
}