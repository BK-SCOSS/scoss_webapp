#include<iostream>
using namespace std;
int main()
{
	int n,a,b;
	int M[n];
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a >> b;
		M[i] = a+b;
	}
	for(int i=0; i<n; i++)
		cout << M[i] << endl;
}
