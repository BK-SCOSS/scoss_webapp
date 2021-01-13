#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int main()
{
	int n, K;
	int *s, *d, *r, *res;

	cin >> n >> K;
	s = new int [n];
	d = new int [n];
	r = new int [n];
	res = new int [n];

	for (int i = 0; i < n; ++i)
	{
		cin >> s[i] >> d[i] >> r[i];
		d[i] += K;
		s[i] += d[i];
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if(s[i] > s[j])
			{
				int temp = s[i];
				s[i] = s[j];
				s[j] = temp;

				temp = d[i];
				d[i] = d[j];
				d[j] = temp;

				temp = r[i];
				r[i] = r[j];
				r[j] = temp;
			}
		}
	}

	res[0] = r[0];

	for (int i = 1; i < n; ++i)
	{
		int b = 0;

		for (int j = 0; j < i; ++j)
		{
			if(s[j] > s[i] - d[i])
				break;

			if(res[j] > b)
				b = res[j];
		}

		res[i] = b + r[i];
	}

	cout << *max_element(res, res + n) << endl;
}