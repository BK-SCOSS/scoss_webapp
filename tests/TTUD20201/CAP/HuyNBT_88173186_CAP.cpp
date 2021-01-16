#include <iostream>
using namespace std;

int main()
{
	int a[100], b[100], n, m;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j]) count ++;
		}
	}
	cout << count;
	return 0;
}
