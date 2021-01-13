#include <iostream>
using namespace std;

int main()
{
	unsigned long long arr[20];
	int s, T;

	cin >> T;

	for (int i = 0; i < 2 * T; ++i)
		cin >> arr[i];

	for (int i = 0; i < T; ++i)
	{
		s = arr[2 * i] + arr[2 * i + 1];
		cout << s << "\n";
	}

	return 0;
}