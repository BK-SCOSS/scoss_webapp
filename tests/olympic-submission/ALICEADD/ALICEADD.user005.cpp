#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<b; ++i)

using namespace std;

string add(string a, string b){
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    int nho = 0;
    string result = "";
    for(int i=a.length()-1; i>=0; --i){
        int c = a[i] - 48 + b[i] - 48 + nho;
        nho = c/10;
        c = c % 10;
        result = char(c+48) + result;
    }
    if (nho>0) result = "1" + result;
    while (result.length()>1 && result[0] == '0') result.erase(0,1);
    return result;
}

int main()
{
    int n;
    string a,b;

    //freopen("aliceadd.inp","r",stdin);
    scanf("%d\n", &n);

    FOR(i,0,n){
        cin >> a >> b;
        cout << add(a,b) << "\n";
    }
}
