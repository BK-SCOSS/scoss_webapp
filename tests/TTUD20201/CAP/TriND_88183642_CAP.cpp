#include<bits/stdc++.h>
using namespace std;
#define MAX 2e9;
set<int> a,b;
int memory[100];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int tempA;
		cin >> tempA;
		for(int j=0;j<tempA;j++){
			int soA;
			cin >> soA;
			auto temp = a.insert(soA);
		}
		int tempB;
		cin >> tempB;
		for(int j=0;j<tempB;j++){
			int soB;
			cin >>soB;
			auto temp = a.insert(soB);
		}
		int tongphantu = a.size()+b.size();
		for(int x : a)
		{
			b.insert(x);
		}
		int temp = b.size();
		memory[i]=tempA+tempB-tongphantu;
	}
	for(int i=0;i<n;i++)
	{
		cout << memory[i];
	}
	return 0;
}
