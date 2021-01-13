#include <iostream>
#include <string>
using namespace std;

int N;
int a[7];
bool had[10];
int count = 0;

void computerQ(int* a)
{
	int SOICT = 10000*a[2] + 1000*a[4] + 100*a[5] + 10*a[6] + a[3];
	int HUST= 1000*a[0] + 100*a[1] + 10*a[2] +a[3];
	if ( HUST + SOICT == N) count++;
}

void Try(int k)
{
	for (int i = 1; i <= 9; i++)
	{
		if (! had[i])
		{
			a[k] = i;
			had[i] = true;
			if (k == 6) computerQ(a);
			else Try(k + 1);
			had[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	
	if (N % 2)
	{
		cout << 0;
		return 0;
	}
	
	Try(0);
	cout << count;
	
	return 0;
}
