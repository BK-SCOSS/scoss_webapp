#include <iostream>
using namespace std;
int a[100003], f[100003],n,t,res;
int timMax(int a, int b)
{
	if (a > b) return a;
	else return b;

}
void input()
{
	cin >> t;
	for (int h = 0; h < t; h++)
	{
		cin >> n;
		int res = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];

		}
		int m = n;
		f[1] = 1;
		for (int i = 2; i <=n ; i++)
		{
			f[i] = 1;
			for (int j = i-1; j > 0; j--)
			{
				if (a[i] - a[j]==1)
				{
					f[i] = f[j] + 1;
					break;
				}
			}
		}
		for (int i = 1; i <=n ; i++)
		{
			res = timMax(res, f[i]);
		}
		cout << res << endl;
		
		
	}
	
	
}

int main()
{
	//freopen("input.txt", "r", stdin);
	input();
	
	return 0;

}