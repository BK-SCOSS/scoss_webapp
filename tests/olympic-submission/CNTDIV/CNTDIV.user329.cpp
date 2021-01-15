#include <bits/stdc++.h>
using namespace std;

void Solve()
{
	long long int cnt = 0;
	long long int N; cin >> N;
	long long int T = N*(N + 1)*(N + 2);
	for (int i = 2; i < T; i++)
	{
		if (T*T % i == 0 && T % i != 0) cnt++;
	}
	cout << cnt << endl;
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