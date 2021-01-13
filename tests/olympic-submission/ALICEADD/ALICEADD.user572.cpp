#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
const int base = 1e9;

typedef long long ll;
typedef vector<int> BigInt;
ll a[N], res = 0;
int n;
BigInt ans;

stack <ll> cc1;
stack <ll > cc2;

void Print(BigInt a) {
	printf("%d", a.back());
	for (int i = a.size()-2; i >= 0; i--) printf("%09d", a[i]);
	printf("\n");
}

BigInt bigInt(string s) {
	BigInt a;
	while (s.size() % 9 != 0) s = '0' + s;
	for (int i = s.size() - 1; i > 0; i -= 9) {
		int x = 0;
		for (int j = i - 9 + 1; j <=i; j++) x = x * 10 + s[j] - '0';
		a.push_back(x);
	}
	return a;
}

BigInt bigInt(long long x) {
	BigInt a;
	if (x < 1e9) a.push_back(x);
	else{
        if (x!= 1e18){
            int tt = x % int (1e9);
            a.push_back(tt);
            x = x / 1e9;
            a.push_back(x);
        }
        else{
            a.push_back(0);
            a.push_back(0);
            a.push_back(1);
        }
	}

	return a;
}

void Set(BigInt &a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt operator * (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c (a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++) {
		ll g = 0ll;
		for (int j = 0; j < b.size(); j++) {
			g += c[i+j] + (ll) a[i] * b[j];
			c[i+j] = g % base;
			g /= base;
		}
		if (g > 0) c[i+b.size()] += g;
	}
	Set(c);
	return c;
}

bool operator >= (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	if (a.size() != b.size())
		return (a.size() > b.size());
	for (int i = a.size()-1 ; i >=0; i--)
        if (a[i] != b[i]) return a[i] > b[i];
	return true;
}

BigInt operator + (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c;
	int g = 0;
    for (int i = 0;  i < max(a.size(), b.size()); i++) {
		if (i < a.size()) g += a[i];
		if (i < b.size()) g += b[i];
		c.push_back(g%base);
		g /= base;
	}
	if (g > 0) c.push_back(g);
	Set(c);
	return c;
}

BigInt operator - (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c;
	int g = 0;
	for (int i = 0; i < a.size(); i++) {
		g += a[i];
		if (i < b.size()) g -= b[i];
		if (g >= 0) c.push_back(g), g = 0;
		else c.push_back(g+base), g = -1;
	}
	Set(c);
	return c;
}

//******************//

int main(){
    //freopen("GRAVELS.INP", "r", stdin);
    //freopen("GRAVELS.OUT", "w", stdout);
    int T;
    cin>>T;
    while (T--){
        string a, b;
        cin>>a>>b;
        BigInt X = bigInt(a);
        BigInt Y = bigInt(b);
        Print(X + Y);
    }
}
