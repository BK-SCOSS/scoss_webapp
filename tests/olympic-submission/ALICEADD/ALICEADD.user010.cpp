#include <bits/stdc++.h>
using namespace std;
	
int main()
{
	int t;
	string a,b;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		cin>>a>>b;
		while (a.length()<b.length())
		{
			a = '0' + a;
		}
		while (b.length()<a.length())
		{
			b = '0' + b;
		}
		a = '0' + a;
		b = '0' + b;
		string c = "";
		int carry = 0;
		for (int j = b.length()-1; j >= 0; j--)
		{
			int c1 = b[j]-48;
			int c2 = a[j]-48;
			int last = ((c1 + c2 + carry)%10);
			carry = (c1+c2+carry)/10;
			char c3 = last + 48;
			c = c3 + c;
			//cout<<c3<<endl;
		}	
		//cout<<a<<b;
		int mark = 0;
		for (int j = 0; j < c.length(); j++)
		{
			if (c[j]!='0')
			{
				mark = j;
				break;
			}
		}
		for (int j = mark; j < c.length(); j++)
		{
			cout<<c[j];
		}
		cout<<endl;
	}
	return 0;
}
