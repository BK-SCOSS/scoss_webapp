
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        long long a[n];
        int x[n];
        for(int i =0 ; i< n; i++){
            cin >> a[i];
        }
        int b[n];
        for(int i =0 ; i< n; i++){
        	b[i] = 0;
		}
        for(int i =0 ; i< n-1; i++){
            int k = 1;
            int cnt = 1;
            for(int j = i+ 1; j <n; j++){
                if(a[j] - a[i] == k){
                    cnt ++;
                    k++;
                }
            }
            b[i] = cnt;
        }
        int max = 1;
        for(int i = 0; i< n; i++){
            if(max < b[i]){
                max = b[i];
            }
        }
        cout << max << endl;

    }
    return 0;
}
