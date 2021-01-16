#include<iostream>
#include<vector>
using namespace std;
int x, c;
int INF = -99999999;
//int findMax(vector<int> &a){
//    int temp = INF;
//    for(int i=0; i<a.size(); i++){
//        temp = max(temp, a[i]);
//    }
//    return temp;
//}
void Try(vector<int> &a){
    if(a.size() == 1) return;
    vector<int> b;
    int tmpMax = INF;
    if(a.size() % 2 == 0){
        int i = 0;
        while(i<a.size()){
            int tmp = a[i]+a[i+1];
            tmpMax = max(tmpMax, tmp);
            b.push_back(tmp);
            i = i+2;
        }
        c += tmpMax;
    }
    if(a.size() % 2 != 0){
        int i = 0;
        while(i != (a.size()-1)){
            int tmp = a[i]+a[i+1];
            tmpMax = max(tmpMax, tmp);
            b.push_back(tmp);
            i = i+2;
        }
        b.push_back(a[i]);
        c += tmpMax;
    }
    Try(b);
}
int main(){
    int test;
    vector<int> ans;
    cin >> test;
    while(test--){
        int n;
        c=0;
        cin >> n;
        vector<int> a;
        for(int i=0; i<n; i++){
            cin >> x;
            a.push_back(x);
        }
        Try(a);
        ans.push_back(c);
    }
    for(auto i=ans.begin(); i!=ans.end(); i++){
        cout << *i << endl;
     }
}
