#include <bits/stdc++.h>
using namespace std;

void Solve()
{
	string A, B; cin >> A >> B;
	if (A.size() > B.size())
	{
		string tmp = A, A = B, B = A;
	}
	while (A.size() < B.size())
	{
		A = "0" + A;
	}
	int nho = 0;
	string res = "";
	for (int i = A.size() - 1; i >= 0; i--)
	{
		int tmp = A[i] + B[i] + nho - 2 * '0';
		nho = tmp / 10;
		res = std::to_string(tmp % 10) + res; 
	}
	if (nho > 0) res = to_string(nho) + res;
	cout << res << endl;
}

int main()
{
	int numtest = 1;
	cin >> numtest;
	for (int i = 1; i <= numtest; i++)
	{
		Solve();
	}

//	system("pause");
	return 0;
}
