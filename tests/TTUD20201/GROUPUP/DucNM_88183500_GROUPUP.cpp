#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >>t;
    for (int k=0; k<t; k++){
        int n,tg,dem=0;
        cin >> n;
        vector <int> a;
        for (int i=0;i<n;i++){
            cin >> tg;
            a.push_back(tg);
        }
        while (a.size()!=1){
            for (int i=1;i<a.size();i++)
            if (i%2==1){
                a[i-1] += a[i];
            }
            int k=0,mx=0;
            for (int i=0;i<a.size();i++){
                if (k%2==1){
                    a.erase(a.begin()+i);
                    i--;
                }
                k++;
            }
            for (int i=0; i<a.size(); i++){
                mx = max(mx,a[i]);
            }
            dem += mx;
        }
        cout << dem << endl;
    }
}



