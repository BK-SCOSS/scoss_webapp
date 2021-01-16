#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T> 0){
        cin >>n;
        int step = log2(n);
        if(pow(2,step) != n){
            step +=1;
        };

        vector<int> arr[step+2];
        vector<int> vt;
        for(int i = 0; i< n;i++){
            int tmp = 0;
            cin >> tmp;
            arr[1].push_back(tmp);
        }
        int indx = 1;
        while(indx <= step){
            int mv = 0;
            int sz = arr[indx].size();
            for(int i = 0; i< sz;i++){
                if(i == sz-1){
                    arr[indx+1].push_back(arr[indx][i]);
                    i++;
                }else{
                    int s = arr[indx][i]+ arr[indx][i+1];
                    if(s >mv) mv = s;
                    arr[indx+1].push_back(s);
                    i++;
                }

            }
            vt.push_back(mv);
            indx++;
        }
        int rs=0;
        for(int i=0; i<vt.size();i++){
            rs+= vt[i];
        }
        cout << rs<< endl;
        T--;
    }
}
