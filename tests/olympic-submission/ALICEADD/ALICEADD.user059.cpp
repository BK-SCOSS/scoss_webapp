#include <bits/stdc++.h>

using namespace std;
#define read() freopen("input.txt","r",stdin) 
#define write() freopen("output.txt","w",stdout) 
#define ll long long
#define ull unsigned long long
typedef pair<int, int> ii;      
typedef vector<ii> vii;      
typedef vector<int> vi; 
typedef vector<ll> vl;
const ll INF = 1e9;
const int MAXN = 1e6+5;
string operator+(string a, string b) {
    string ans = "";
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    int carry = 0, rem;
    for (int i = a.length() - 1; i >= 0; --i) {
        rem = (a[i] - '0' + b[i] - '0') + carry;
        ans = (char(rem % 10 + '0')) + ans;
        carry = rem / 10;
    }
    if (carry > 0) ans = "1" + ans;
    return ans;
}

string operator-(string a, string b) {
    string ans = "";
    bool neg = 0;
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    if (a < b) swap(a, b), neg = 1;
    int carry = 0, rem;
    for (int i = a.length() - 1; i >= 0; --i) {
        rem = a[i] - b[i] - carry;
        carry = 0;
        while (rem < 0) {
            ++ carry;
            rem += 10;
        }
        ans = (char(rem % 10 + '0')) + ans;
    }
    while (ans.length() > 1 && ans[0] == '0') ans.erase(0, 1);
    if (neg) ans = "-" + ans;
    return ans;
}

string operator* (string a, string b) {
    long long sav[2050];
    for (int i = 0; i < 2050; i++)
        sav[i] = 0;
    string ans = "";
    int carry = 0, rem;
    a = "0" + a;
    b = "0" + b;
    for (int i = a.length() - 1; i >= 0; --i)
        for (int j = b.length() - 1; j >= 0; -- j)
            sav[i + j] += ((a[i] - '0') * (b[j] - '0'));
    for (int i = a.length() + b.length() - 2; i >= 0; --i) {
        rem = sav[i] + carry;
        carry = rem / 10;
        ans = char(rem % 10 + '0') + ans;
    }
    while (ans.length() > 1 && ans[0] == '0') ans.erase(0, 1);
    return ans;
}

int main() {
//	read();
//	write();
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test = 1;
	cin>>test;
	while(test--){
		string A, B;
		cin>>A>>B;
		cout<<A+B<<endl;	
	}
}
