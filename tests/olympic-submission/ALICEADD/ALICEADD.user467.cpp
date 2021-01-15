#include <bits/stdc++.h>
using namespace std;
string chuanHoa(string s)
{
	int k = 0;
	while(s[k] == '0') k = k + 1;
	string res = "";
	for(int i = k ; i < s.size() ; i ++)
		res = res + s[i];
	return res;
}
string sum(string a, string b)
{
	string res = "";
	a = chuanHoa(a);
	b = chuanHoa(b);
	while(a.size() > b.size())
	{
		b = '0' + b;
	}
	while(b.size() > a.size())
	{
		a = '0' + a;
	}
	a = '0' + a;
	b = '0' + b;
	int du = 0;
	for(int i = a.size() - 1 ; i >= 0; i --)
	{
		int tong = a[i] - '0' + b[i] - '0' + du;
		if(tong >= 10)
		{
			tong = tong - 10;
			du = 1;
		}
		else du = 0;
		res =  char(tong + '0') + res;
	}
	res = chuanHoa(res);
/*	string res1 = "";
	int k = 0;
	while(res[k] == '0') k++;
	for(int i = k ; i < res.size() ; i ++)
		res1 = res1 + res[k];*/
	return res;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string a, b;
		cin >> a >> b;
		//cout << chuanHoa(a) <<" "<<chuanHoa(b) << endl;
		cout << sum(a,b) << endl;
	}
}
