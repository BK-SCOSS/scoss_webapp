#include <bits/stdc++.h>
using namespace std;
int a[10000001], b[10000001];
int T,n,m;

int Count(int n, int m){
    cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cin >> m;
        for (int j = 0; j < m; j++){
            cin >> b[j];
        }
int count = 0;
   for(int i = 0; i< n; i++){
    for(int j = 0; j < m; j++){
        if (a[i] == b[j]) count++;
    }
   }
   return count;
}

int main(){
   cin >> T;
   int A[T];
   for (int z = 0; z < T; z++){
    A[z] = Count(n,m);
   }
   for(int z = 0; z < T; z++) cout << A[z] <<endl;
   return 0;

}
