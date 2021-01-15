#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n;
	cin >> n;
	long long a,b;
	long long arr[n];
	for(int i =0;i < n;i++)
	{
		cin >> a >> b;
		arr[i] = a+b;
	}
	for(int i =0;i<n;i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}

