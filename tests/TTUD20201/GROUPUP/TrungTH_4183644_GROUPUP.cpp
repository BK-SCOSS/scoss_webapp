#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
int n;
int T;



int main()
{
    cin >> T;
    while(T--){
        int rs = 0;
        queue<int> Q1, Q2;
        cin >> n;
        for(int i=0;i<n;i++){
            int u;
            cin >> u;
            Q1.push(u);
        }
        vector<int> time;
        while(1){
            int tmp = 0;
            while(!Q1.empty()){
                int u =0, v=0;
                int c;
                if(Q1.size()==1){
                    c = Q1.front();
                    Q1.pop();
                    Q2.push(c);
                    break;
                }
                u = Q1.front();
                Q1.pop();
                v = Q1.front();
                Q1.pop();
                c = u+v;
                Q2.push(c);
                tmp = tmp > c ? tmp : c;
            }
            time.push_back(tmp);
            if(Q2.size() == 1){
                break;
            }
            else{
                while(!Q2.empty()){
                    Q1.push(Q2.front());
                    Q2.pop();
                }
            }
        }

        for(int i=0;i<time.size();i++){
            rs = rs + time[i];
        }
        cout << rs << endl;
    }
    return 0;
}
