#include<bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define INF 1e18
#define BASE 100000000ll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> bigint;

void fix(bigint &a) {
    a.push_back(0);
    for (int i = 0; i < a.size(); ++i)  {
        a[i+1] += a[i] / BASE; a[i] %= BASE;
        if (a[i]<0) { a[i]+=BASE; a[ i + 1] --; }
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

bigint to_bigint(ll x)  {
    bigint a;
    a.push_back(x % BASE); a.push_back(x/ BASE);
    return fix(a), a;
}

bigint to_bigint(string s) {
    bigint a(s.length() / 8 + 1);
    for (int i=0; i<s.length();++i) {
    int x= (s.length()-i -1)/8;
    a[x] = a[x] * 10 + (s[i]-'0');
    }
    return fix(a),a;
}

bool operator < (const bigint &a, const bigint &b)  {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i= a.size() -1;i>=0; --i)
        if (a[i] != b[i]) return a[i]<b[i];
    return false;
}

void operator += (bigint &a, const bigint &b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0;i < b.size(); ++i) a[i] += b[i];
    fix(a);
}

bigint operator * (const bigint &a, const bigint &b) {
    bigint c(a.size() + b.size());
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0;j < b.size(); ++j)
            c[i + j] += a[i]*b[j];
    return fix(c), c;
}

void operator -= (bigint &a, const bigint &b) {
    for (int i = 0; i < b.size(); ++i) a[i] -= b[i];
    fix(a);
}

void operator *= (bigint &a, int x) {
    for (int i=0; i< a.size(); ++i) a[i]*=x;
    fix(a);
}

bigint operator + (bigint a, const bigint &b) { a+= b; return a; }

bigint operator - (bigint a, const bigint &b) { a-= b; return a; }

bigint operator * (bigint a, int x) { a*= x; return a; }

bigint operator / (const bigint &a, int b) {
    bigint c(a.size());
    ll cur = 0;
    for (int i = a.size() - 1; i>= 0; --i) {
        cur = cur * BASE + a[i];
        c[i] = cur / b;
        cur %= b;
    }
    return fix(c), c;
}

void print(const bigint &a) {
    printf("%lld", a.back());
    for (int i = a.size() - 2; i>= 0;--i) printf("%08lld", a[i]);
    cout<<'\n';
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
    string s;
    string s2;
    cin>>s;
    cin>>s2;
    bigint a=to_bigint(s);
    bigint b = to_bigint(s2);
    a = a + b;
    print(a);
    }
}
