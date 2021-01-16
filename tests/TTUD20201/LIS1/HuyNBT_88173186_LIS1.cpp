#include<iostream>
using namespace std;

int main()
{
	int n, count = 1;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int x = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] - x == 1)
		{
			count ++;
			x = a[i];
		}
	}
	cout << count;
	return 0;
}
