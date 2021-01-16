//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int a[100003], b[100003],n,t;
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
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];

		}
		int m = n;
		int res = 0;

		int time = 0;

		while (m != 1)
		{
			int j = 1;
			res = 0;
			int index = 1;
			int temp = 1;
			while (j <= m)
			{
				if (j == m)
				{
					res = max(res, a[j]);
					b[index] = a[j];
					j += 1;
					temp = 0;
				}

				else
				{
					res = max(res, a[j] + a[j + 1]);
					b[index] = a[j] + a[j + 1];
					j += 2;
				}
				index++;
			}
			//cout << res << endl;
			time = time + res;
			if (temp == 1)
				m = m / 2;
			else
				m = m / 2 + 1;
			for (int z = 1; z <= m; z++)
			{
				a[z] = b[z];
			}
		}
		cout << time << endl;
	}


}

int main()
{
	input();
	return 0;

}
