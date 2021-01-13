#include <iostream>

using namespace std;

int main()
{
	int T;
	do
	{
		cin >> T;
	} while ((T < 0) || (T > 10));
	int a[20];
	for (int i = 0; i < T; ++i)
	{
		cin >> a[2*i] >> a[2*i + 1];
	}
	for (int i = 0; i < T; ++i)
	{
		cout << a[2 * i] + a[2 * i + 1] << endl;
	}
}

