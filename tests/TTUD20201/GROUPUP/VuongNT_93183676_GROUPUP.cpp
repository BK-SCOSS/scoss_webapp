#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int ans =0;
        int k;
        cin >> k;
        queue<int> A;
        for(int i = 0; i < k; i++){
            int t;
            cin >> t;
            A.push(t);
        }
        int ks = A.size() / 2;
        while (A.size())
        {   int tempmax = 0;
            if(A.size() > 1){
            
                int temp2 = A.front();
                A.pop();
                int temp1 = A.front();

                A.pop();
                tempmax = max(tempmax, temp1+temp2);
                A.push(temp1+temp2);
                ks--;
                
            }else{
                tempmax = A.front();
                A.pop();
                ks--;
            }
            if(ks == 0){
                ans += tempmax;
                ks = A.size() / 2;
            }
        }
        
        cout << ans;
    }
}