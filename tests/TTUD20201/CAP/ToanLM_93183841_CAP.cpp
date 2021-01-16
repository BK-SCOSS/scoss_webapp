#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n,m;
int a[N];
int b[N];
int T;

int main(){
    cin >> T;
    int x[T];
    for(int k=1;k<=T;k++){
        cin >> n;
        for (int i=0; i<n;i++){
            cin >> a[i];
        }
        cin >> m;
        for (int j=0;j<m;j++){
            cin >> b[j];
        }
        int cnt=0;
        for (int i=0;i<n;i++){
         for (int j=0;j<m;j++){
            if (a[i]==b[j]){
               cnt++;
            }
         }
        }
        cout << cnt;
    }
}
