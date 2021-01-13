#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n=-1;
	while(n<0 || n> 10)
	{
		cin>>n;
	}
	if(n==0) return 0;
	unsigned long long int a,b;
	vector <unsigned long long int > c ;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a+b >= 0 )
		{
			c.push_back(a+b);
		}
	}
	for(int i=0;i<c.size();i++)
	{
		cout<<c[i]<<endl;
	}
	
	
	return 0;
}
