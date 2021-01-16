#include <iostream>
#include <vector>
using namespace std;

int n, t;
int max_len = 0;
int a[100001];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        int len = 0;
        for(int i=1; i<n; i++){
            int cnt = 1;
            int tmp = a[i];
            for(int j=i+1; j<=n; j++){
                if(a[j] == tmp + 1){
                    cnt +=1;
                    tmp = a[j];
                }
            }
            len = max(len, cnt);
        }
        cout << len;
    }
    return(0);
}