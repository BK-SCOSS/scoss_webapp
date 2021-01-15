#include<iostream>

using namespace std;

int main ()
{
	int Q;
	cin >> Q;
	int N[Q],T[Q];
	for (int i = 0 ; i < Q; i++)
	{
		cin >> N[i];
	}
	for (int i = 0 ; i < Q; i++)
	{
		T[i] = N[i] * (N[i] + 1) * (N[i] + 2);
		int dem = 0;
		for (int j = 1; j < T[i]; j++)
		{
			if ((T[i] * T[i]) % j ==0 && T[i] % j != 0)
			dem++;
		}
		cout << dem << endl;
	}
	return 0;
}
