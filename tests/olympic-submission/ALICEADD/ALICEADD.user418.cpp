#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		unsigned long long a, a1, a2, b, b1, b2, c;
		cin >> a >> b;
		a1 = a / 10;
		a2 = a % 10;
		b1 = b / 10;
		b2 = b % 10;
		c = a1 + b1;
		if (a2 + b2 >= 10)
			c++;
		if (c > 0)
			cout << c;
		cout << (a2 + b2) % 10;
	}
}