#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int t, a, b;
	vector<int> arr;
	
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> a >> b;
		arr.push_back(a+b); 
	}
	for (int i = 0; i < t; i++)
	{
		cout << arr[i]<<endl;
	}
}