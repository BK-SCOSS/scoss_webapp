#include <bits/stdc++.h>
using namespace std;
int val[30], num[30], id[1000006], ct, n, res;
long long t;
void primeFactors(int x)
{
	if (x % 2 == 0)
	{
		if (!id[2])
		{
			id[2] = ++ct;
		}
		val[id[2]] = 2;
	}
    while (x % 2 == 0)
    {
        num[id[2]]++;
        x /= 2;
    }
    for (int i = 3; i <= sqrt(x); i += 2)
    {
    	if (x % i) continue;
    	if (!id[i])
    	{
    		id[i] = ++ct;
    		val[id[i]] = i;
		}
        while (x % i == 0)
        {
            num[id[i]]++;
            x /= i;
        }
    }
    if (x > 2)
    {
		if (!id[x])
    	{
    		id[x] = ++ct;
    		val[id[x]] = x;
		}
		num[id[x]]++;
	}
}
int resb = 0;
void brute()
{
    resb = 0;
    long long t2 = t * t;
    for (int i = 2; i <= sqrt(t2); ++i)
    {
        if ((t2 % i == 0) && (t % i))
        {
            resb++;
        }
    }
}
void Try(long long curmul, int curid)
{
    if (curid > ct)
    {
        if (t % curmul)
        {
            res += 1;
        }
        return;
    }

    if (curid <= ct) Try(curmul, curid + 1);
    long long tmp = curmul;
    for (int i = 1; i <= 2 * num[curid]; ++i)
    {
        if ((t + tmp - 1) / tmp <= val[curid]) break;
        tmp *= val[curid];
        Try(tmp, curid + 1);
    }
}
void solve()
{
	ct = 0; res = 0;
	cin >> n;
	primeFactors(n);
	primeFactors(n + 1);
	primeFactors(n + 2);
	t = n;
	t *= (n + 1);
	t *= (n + 2);
//	brute();
//	cout << resb << '\n';
	Try(1LL, 1);
	cout << res << '\n';
	for (int i = 1; i <= ct; ++i)
    {
	    id[val[i]] = 0;
	    val[i] = num[i] = 0;
    }
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--)
	{
		solve();
	}
}
