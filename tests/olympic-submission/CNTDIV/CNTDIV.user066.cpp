#include <iostream>
using namespace std;


int main() 
{
	int Q;
	cin >> Q;
	int T[Q];
	int dem[Q];
	int N;
	for (int i = 0; i < Q; i++)
	{
		dem[i] = 0;
		cin >> N;
		T[i] = N*(N+1)*(N+2);
		for (int j = 1; j < (T[i]); j++ )
		{
			if((((T[i] * T[i]) % j) == 0) && ((T[i]% j) != 0)) dem[i]++; 
		}
	}
	for (int i = 0; i < Q; i++) cout << dem[i] << "\n";
	return 0;
}
