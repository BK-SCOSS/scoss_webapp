#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
long long int num(long long int n)
{
	long long int dem = 0;
	long long int t = n * (n + 1) * (n + 2);
	for (long long int i = 1; i <= sqrt(t * t); i++)
	{
		if ((t * t) % i == 0 && t % i != 0&&i<t) dem++;
	}
	return dem;
}
int main()
{
	long long int q,n;
	cin >> q;
	vector<long long int> arr;
	for (int i = 1; i <= q; i++)
	{
		cin >> n;
		arr.push_back(num( n));
	}
	for (int i = 0; i < q; i++)
	{
		cout << arr[i];
	}


}