#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

vector<int> v;
int a[MAXN], n, t;

void factor(int n)
{
	int x1 = n, x2 = n + 1, x3 = n + 2, cnt = 0;
	v.clear();
	memset(a, true, sizeof a);
	for (int i = 2; i <= sqrt(n + 2); i++)
	{
		if (!a[i])
			continue;
		for (int j = i; j <= sqrt(n + 2); j++)
			a[i] = false;
		cnt = 0;

		while (x1 % i == 0)
		{
			cnt++;
			x1 /= i;
		}
		while (x2 % i == 0)
		{
			cnt++;
			x2 /= i;
		}
		while (x3 % i == 0)
		{
			cnt++;
			x3 /= i;
		}
		if (cnt != 0)
			v.push_back(cnt);
	}
	if (x1 != 1)
		v.push_back(1);
	if (x2 != 1 && x1 != x2)
		v.push_back(1);
	if (x3 != 1 && x1 != x3 && x2 != x3)
		v.push_back(1);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		factor(n);
		long long num1 = 1, num2 = 1;
		for (auto x : v)
		{
			num1 = num1 * (2ll * x + 1);
			num2 = num2 * (1ll * x + 1);
		}
		num1--;
		num2--;
		cout << (num1 - 2 * (num2)) / 2 << endl;
	}
	return 0;
}
