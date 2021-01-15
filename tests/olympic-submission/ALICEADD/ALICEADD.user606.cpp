#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{   int T;
cin>>T;
  for(int i=1; i <= T; i++)
{	long long a;
	long long b;
	cin>>a;
	cin>>b;
	long long c=a+b;
	string result;
	ostringstream convert;
	convert<<c;
	result=convert.str();
	cout<<result;
	}
	}
	
