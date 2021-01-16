#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    for (int k=0; k<t; k++){
        int n,dem=0,tg;
        cin>>n;
        vector <int> a;
        for (int i=0;i<n;i++){
            cin >> tg;
            a.push_back(tg);
        }
        for (int i=0;i<a.size()-1;i++)
            for (int j=i+1; j<a.size();j++ )
            if (a[i]==a[j]) {
                a.erase(a.begin()+j);
                j--;
            }
        int m;
        cin >> m;
        int b[m];
        for (int i=0;i<m;i++)
            cin >> b[i];
        for (int i=0; i<a.size();i++)
            for (int j=0; j <m; j++)
            if (a[i]==b[j]) {
                dem++;
                break;
            }
        cout << dem <<endl;
    }
}
