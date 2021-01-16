#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int j = 0;
	if (n % 2 == 0) m = n / 2;
	else m = (n + 1) / 2;
	int b[m];
	if (n % 2 == 0)
	{
	    for (int i = 0; i < n; i += 2)
	    {
		    b[j] = a[i] + a[i + 1];
		    j++;
	    }
	}
	else
	{
	    b[m - 1] = a[n - 1];
		for (int i = 0; i < n -1; i += 2)
		{
		    b[j] = a[i] + a[i + 1];
		    j++;
	    }
	}
	int max = b[0];
	for (int i = 1; i < m; i++)
	{
		if (b[i] > max) max = b[i];
	}
	cout << max;
	return 0;
}
