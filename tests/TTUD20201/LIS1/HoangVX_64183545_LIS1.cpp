#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int,int>> a(100000);
int n,T;
int main(){
    cin>> T;
    vector<int> u;
    while(T>0){
        T--;
        int x;
        cin>> n;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            a[i].first = x;
            a[i].second = i;
        }
        sort(a.begin(), a.begin()+n);
        /*for(int i=0;i<n;i++){
            cout<< a[i].first<<" "<< a[i].second<< endl;
        }*/
        int result = 1;
        u.push_back(0);
        for(int i=1;i<n;i++){
            int v = u.back();
            if(a[i].first==a[v].first+1&&a[i].second>a[v].second){
                u.push_back(i);
                continue;
            }
            if(a[i].first>a[v].first+1){
                if(u.size()>result){
                    result = u.size();
                }
                u.clear();
                u.push_back(i);
            }
        }
        result = max(result,int(u.size()));
        cout<< result<< endl;
    }
}
/*
1
6
3 1 2 3 4 5
*/
