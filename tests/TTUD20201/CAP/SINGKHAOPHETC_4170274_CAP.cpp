#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[109];
		for (int i = 1; i <= n; i++)
		cin >> a[i];
		int m; 
		cin >> m;
		int b[109];
		for (int i = 1; i <= m; i++)
		cin >> b[i];
		int cnt = 0;
		for(int i = 1; i <= n ; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if (a[i] == b[j] ) cnt++;
			}
		}
		cout << cnt << endl;
	}
}

	


