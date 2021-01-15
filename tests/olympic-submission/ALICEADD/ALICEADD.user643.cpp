#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector <int> vi;
const int base = 1e4;
bool sign = false;
string A, B;
void fix(vi &a)
{
	a.push_back(0);
	for (int i = 0; i < (int)a.size() - 1; ++i)
	{
		a[i + 1] += a[i] / base, a[i] %= base;
		if (a[i] < 0) a[i] += base, a[i + 1]--;
	}
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}
vi Integer(string s)
{
	vi a;
	for (int i = (int) s.size() - 1; i >= 0; i -= 4)
	{
		int num = 0;
		for (int j = max (0LL, i - 3); j <= i; ++j)
            num = num * 10 + (long long)s[j] - '0';
        a.push_back(num);
	}
	return a;
}
bool operator < (vi a, vi b)
{
    fix(a), fix(b);
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; --i)
        if (a[i] != b[i]) return a[i] < b[i];
    return false;
}
vi operator + (vi a, vi b)
{
	vi c(max(a.size(), b.size()));
	for (int i = 0; i < (int)c.size(); ++i)
	{
		if (i < (int) a.size()) c[i] += a[i];
        if (i < (int) b.size()) c[i] += b[i];
	}
	return fix(c), c;
}
vi operator - (vi a, vi b)
{
	if (a < b) swap(a, b), sign = true;
	vi c(max(a.size(), b.size()));
	for (int i = 0; i < (int)c.size(); ++i)
	{
		if (i < (int) a.size()) c[i] += a[i];
        if (i < (int) b.size()) c[i] -= b[i];
	}
	return fix(c), c;
}
vi operator * (vi a, vi b)
{
	vi c(a.size() + b.size());
	for (int i = 0; i < (int)a.size(); ++i)
		for (int j = 0; j < (int)b.size(); ++j)
			c[i + j] += a[i] * b[j];
	return fix(c), c;
}
void Print(vi a)
{
    cout << a.back();
    for (int i = a.size() - 2; i >= 0; i--)
        cout << setw(4) << setfill('0') << a[i];
    cout << '\n';
}
void solve()
{
	cin >> A >> B;
	vi a = Integer(A);
	vi b = Integer(B);
	Print(a + b);
}
#undef int
int main()
{
	#define int long long	
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--)
	{
		solve();
	}
} 
