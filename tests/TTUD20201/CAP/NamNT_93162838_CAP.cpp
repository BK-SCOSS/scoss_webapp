#include <bits/stdc++.h>
#include <vector>
using namespace std;
unsigned int T;
int count = 0;
int Solve(vector<int>  a,vector<int> b)
{
	int n = a.size();
	int m = b.size();
	int count = 0;
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<m;j++)
		{
			if (a[i] == b[j])
			{
				count++;
			}
		}
	}
	
	return count;
}
int main ()
{
	cin >> T;
	while (T--)
	{
		unsigned int n,m;
		cin >> n ;
		vector<int> a;
		vector<int> b;
		while(n>0)
		{
			int k;
			cin >> k;
			a.push_back(k);
			n--;
		}
		cin >> m;
		while(m>0)
		{
			int k;
			cin >> k;
			b.push_back(k);
			m--;
		}
		// std::sort(a.begin(),a.end());
		// cout << "aaa";
		// cout << a[0] << a[1] << a[2] << a[3];
		// for (int i = 0;i<n;i++)
		// {
		// 	cout << a[i];
		// }
		// std::sort(b.begin(),b.end());
		// cout << b[0] << b[1] << b[2];
		// for (int i = 0;i<m;i++)
		// {
		// 	cout << b[i];
		// }
		cout << Solve(a,b);

	}
}