#include<iostream>
#include<string>
using namespace std;
string add(string a, string b)
{
	while(a.length()<b.length()) a='0'+a;
	while(b.length()<a.length()) b='0'+b;
	string c="";
	//cout<<a<<" "<<b;
	int t =0;
	for(int i=a.length()-1;i>=0;i--)
		{
			t=(int)a[i]+(int)b[i]-48*2+t;
		//	cout<<(int)a[i]+(int)b[i]-48*2+t<<endl;
			if (t<10) 
				{
					c=char(t+48)+c;
					t=0;
				}
			else 
				{
					c=char(t-10+48)+c;
					t=1;
				}
		}
	if (t==1) c="1"+c;
	return c;
}
int main()
{
	string a,b;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
		{
			cin>>a>>b;
			cout<<add(a,b)<<endl;
		}
	return 0;
}
