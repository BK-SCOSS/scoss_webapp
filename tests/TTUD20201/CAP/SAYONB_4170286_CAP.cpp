#include<bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while (test--){
		int non;
		cin>>non;
		int a[109];
		for (int i=1;i<=non;i++)
		cin>>a[i];
		int mom;
		cin>>mom;
		int b[109];
		for(int i=1;i<=non;i++)
		cin>>b[i];
		int count=0;
		for(int i=1;i<=non;i++)
		{
			for(int j=1;j<=mom;j++)
			{
				if(a[i] == b[j]) count++ ;
			}
		}
		cout << count <<endl;
	}
}
