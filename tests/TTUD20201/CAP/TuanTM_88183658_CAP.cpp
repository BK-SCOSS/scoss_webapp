#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int Test;
	cin >> Test;
	vector<int> result;
	
	for (int test = 0; test < Test; test++)
	{
		set <int> a;
		set <int> b;
		set <int> c;
		int l1, l2;
		cin >> l1;
		for (int i = 0; i < l1; i++)
		{
			int temp;
			cin >> temp;
			a.insert(temp);
		}
		cin >> l2;
		for (int i = 0; i < l2; i++)
		{
			int temp;
			cin >> temp;
			b.insert(temp);
		}
		for (int i : a)
		{
			for (int j : b)
			{
				if (i == j)
				{
					c.insert(i);
					b.erase(i);
					break;
				}
			}
		}
		result.push_back(c.size());
	}
	for (int i : result) cout << i << "\n";
	return 0;
}
