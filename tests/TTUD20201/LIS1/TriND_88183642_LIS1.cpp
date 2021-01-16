#include<bits/stdc++.h>
using namespace std;
void print(int memory[],int n){
	for(int metmoi=0;metmoi<n;metmoi++)
	{
		cout << memory[metmoi];
	}
}
int Check(int a[],int n)
{
	for(int tt=1;tt<n;tt++){
		if(a[tt]-a[tt-1]==1)continue;
		else return 0;
	}
	return 1;
}
int main()
{
	int n;
	cin >> n;
	int memory[10];
	for(int i=0;i<n;i++)
	{
		int ans=0,sopt;
		cin >> sopt;
		int arr[sopt];
		int nhodem[sopt];
		int index = 0;
		for(int j=0;j<sopt;j++)
		{
			cin >>arr[j];
		}
		for(int mask = 1 << sopt;mask--;)
		{
//			cout << mask;
			for(int x = 0;x<sopt;x++)
			{
				if(mask >> x & 1)
				{
					nhodem[index]=arr[x];
					index ++;
				}
			}
			cout << nhodem[0];
			if(Check(nhodem,index))
			{
				ans++;
			}
		}
		memory[i]=ans;
	}
	print(memory,n);
	return 0;
}
