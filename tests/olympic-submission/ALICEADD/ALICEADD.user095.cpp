#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		   string a, b;
   int c[30];int k = 0;
   for(int i=0; i<30; i++)
   {
   		c[i] = -1;
   }
   cin>>a;
   cin>>b;
   int n = a.length();
   int m = b.length();
   int du = 0;
   int tong = 0;
   int cc;
   if(n < m)
   {
   		for(int i=n-1; i>=0; i--)
   			{
   				tong = a[i] + b[i+m-n] + du - 2 * '0';
   				du = tong / 10;
   				cc = tong%10;
   				c[k]=cc;k++;
			}
		for(int j=m-n-1; j>=0; j--)
		{
			tong = b[j]-'0' + du;
			du = tong/10;
			cc = tong%10;
			c[k]=cc;k++;

		}
		if(du>0)
		{
			c[k]=du;k++;
		}
   }
   else
   {
   		for(int i=m-1; i>=0; i--)
   			{
   				tong = b[i] + a[i+n-m] - 2*'0' + du; 
   				du = tong / 10;
   				cc = tong%10;
   				c[k]=cc;k++;
			}
		for(int j=n-m-1; j>=0; j--)
		{
			tong = a[j] -'0' + du;
			du = tong/10;
	   		cc = tong%10;
	   		c[k]=cc;k++;
		}
		if(du>0)
		{
			c[k]=du;k++;
		}
   }

   k--;
   while(k>=0)
   {
   		printf("%d",c[k]);
   		k--;
   }
   cout<<endl;
	}
   
}

