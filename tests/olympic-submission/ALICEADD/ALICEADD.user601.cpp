#include<bits/stdc++.h>
using namespace std;
#define val(c) c-'0'
#define str(x) char(x+'0')

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
            string a, b;
    cin >> a >> b;
    while (a.size()!=b.size()){
        if (a.size()<b.size()) a = '0' + a;
        else b = '0' + b;
    }
 //   cout<<a<<" "<<b<<endl;
    long long k = 0, tmp;
    string res = "";
    for (int i=a.size()-1; i>=0; --i){
        tmp =a[i]-'0' + b[i]-'0' + k;
        res = char(tmp%10 +'0') + res;
        k = tmp/10;
    }
    if (k!=0) res =  char(k+'0') + res;
    cout << res<<endl;
    }
}
