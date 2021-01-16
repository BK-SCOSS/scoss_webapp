#include<bits/stdc++.h>
using namespace std;

int T;
int n;

main(){
    cin >> T;
    for(int v=1; v<=T; v++){

        vector<int> A;
        cin >> n;
        for(int i=1; i<=n; i++){
            int ai;
            cin >> ai;
            A.push_back(ai);
        }

        //cout << A.size();
        int ans = 0;
        while(A.size() > 1){
            int time = 0;
            int re = A.size() / 2;
            for(int i=0; i<re; i++){
                //cout << "Gop: " << i << " "<< i+1 << endl;
                A[i] = A[i] + A[i+1];
                time = max(time, A[i]);
                //cout << "Xoa: " << A[i+1] << endl;
                A.erase(A.begin()+(i+1));
            }
            ans += time;
        }


        cout << ans << endl;
    }
}