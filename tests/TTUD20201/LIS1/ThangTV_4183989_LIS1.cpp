#include <bits/stdc++.h>
using namespace std;
int T;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >>T;
    while(T>0){
        cin >>n;
        vector<int> vt;
        for(int i =0;i <n;i++){
            int tmp = 0;
            cin >> tmp;
            vt.push_back(tmp);
        }
        int rs = 1;
        for (int i = 0; i<n;i++){
            int cnt = 1;
            int pivot = vt[i];
            int nn = pivot +1;
            for(int j = i+1;j<n;j++){
                if(vt[j] ==nn){
                    nn++;
                    cnt ++;
                }
            }
            if(cnt > rs) rs = cnt;
        }
        cout << rs <<endl;
        T--;
    }
}
