#include <bits/stdc++.h>

using namespace std;

string a,b;
string slv(string x, string y){
    while (x.size() < y.size()) x = '0' + x;
    while (x.size() > y.size()) y = '0' + y;
    string ans="";
    int nho = 0;
    for (int i=x.size() - 1 ; i >= 0;i--){
        int t = int(x[i]) + int (y[i]) + nho - 48 * 2;
        if (t >= 10) nho = 1;
        else nho = 0;
        ans =   char (t%10 + 48) + ans ;
    }
    if (nho == 1) ans = "1" + ans;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while (t--){
        cin>>a>>b;
        cout<<slv(a,b)<<"\n";
    }
    return 0;
}
