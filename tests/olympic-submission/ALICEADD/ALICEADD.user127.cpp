#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int t;
string a, b;
string add(string a, string b){
    int carry = 0;
    string res = "";
    while(a.size() < b.size()) a = '0' + a;
    while(b.size() < a.size()) b = '0' + b;
    for(int i = a.size() - 1; i>=0; i--){
        int tmp = a[i] - 48 + b[i] - 48 + carry;
        carry = tmp / 10;
        res = (char)(tmp % 10 + 48) + res;
    }
    if(carry > 0){
        res = '1' + res;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << add(a, b) << endl;
    }
    return 0;       
}
