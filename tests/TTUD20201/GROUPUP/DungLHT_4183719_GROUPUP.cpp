#include<bits/stdc++.h>
using namespace std;

int maxVector( vector<int> a){
    int maxA = a[0];
    for(int i = 1; i < a.size(); i++){
        if(maxA < a[i]) maxA = a[i];
    }
    return maxA;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int sum = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(a[i]);
        }
        vector<int> b;
        while(ans.size() > 1){
            if(ans.size() % 2 == 0 ){
                for(int i = 0; i <ans.size(); i=i+2){
                    b.push_back(ans[i]+ans[i+1]);
                }
                sum += maxVector(b);
                ans.clear();
                for(int j = 0; j < b.size(); j++){
                    ans.push_back(b[j]);
                }
                b.clear();
            }
            if(ans.size() % 2 == 1){
                for(int i = 0; i < ans.size() - 1; i=i+2){
                    b.push_back(ans[i]+ans[i+1]);
                }
                b.push_back(ans[ans.size() - 1]);
                sum += maxVector(b);
                ans.clear();
                for(int j = 0; j < b.size(); j++){
                    ans.push_back(b[j]);
                }
                b.clear();
            }
        }
        cout<<sum - ans[ans.size()-1]<<endl;
        t--;
    }
}
