#include<bits/stdc++.h>
using namespace std;
int mang[1000066];
int main(){
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        int A[k];
        for(int i = 0; i < k; i++){
            cin >> A[i];
        }
        memset(mang, 0, sizeof(mang));
        int ans = 0;

        for(int i = 1; i < k; i++){
            int anst = 1 ;
            int temp = A[i];
            for(int j = i+1; j < k ;j++ ){
                if(A[j] - temp == 1){
                    temp = A[j];
                    anst++;

                }
            } 
            ans = max(anst, ans);
        }
        cout << ans << endl;
    }
    
}