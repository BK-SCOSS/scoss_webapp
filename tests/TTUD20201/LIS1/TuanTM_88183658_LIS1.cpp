#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int Test;
	cin >> Test;
	vector<int> result;
	for (int test = 0; test < Test; test++)
	{
		int n;
		cin >> n;
		int a[n+2];
		int b[n+2] = {1};
		int MAXLENGTH = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			int MAX = 0;
			for (int j = 0; j < i; j++)
			{
				if (a[j] == a[i] - 1 && b[j] > MAX)
				{
					MAX = b[j];
					
				}	
			}
			b[i] = MAX + 1;
			MAXLENGTH = max(MAXLENGTH, b[i]);
		}
		result.push_back(MAXLENGTH);
	}
	for (int i : result) cout << i << "\n";
	return 0;
}
