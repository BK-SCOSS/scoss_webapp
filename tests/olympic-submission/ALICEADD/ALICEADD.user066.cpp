#include <iostream>
using namespace std;

// bai a

int main() 
{
	int T;
	int a[10], b[10];
	do
	{
	   cin >> T;
	} while ( (0 > T) || (T > 10) );
	cout << "\n";
	for( int i = 0; i < T; i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	for( int i = 0; i < T; i++) 
	cout <<  "\n" << a[i] + b[i];
	return 0;
}
