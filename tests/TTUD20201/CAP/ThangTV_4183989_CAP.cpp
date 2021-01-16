#include <bits/stdc++.h>
using namespace std;
int T;
int n,m;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T > 0){
        cin >> n;
        vector<int>mark;
        vector<int> a;
        vector<int> b;
        for(int i=0; i<n;i++){
            int tmp = 0;
            cin >> tmp;
            a.push_back(tmp);
        }
        cin >> m;
        for(int i=0; i<m;i++){
            int tmp = 0;
            cin >> tmp;
            b.push_back(tmp);
        }
        int cnt = 0;
        for(int i = 0; i<n;i++){
            int tmp1 = a[i];

            for(int j = 0; j<m;j++){
                int tmp2 = b[j];
                if(tmp1 == tmp2){
                    int mark_tmp = 0;
                    for(int u=0; u<mark.size();u++){
                        if(tmp1 == mark[u]){
                            mark_tmp = 1;
                        }
                    }
                    if(mark_tmp == 0){

                        mark.push_back(tmp1);
                        cnt  ++;
                    }
                }
            }
        }
        cout << cnt <<endl;
        T--;
    }
}
