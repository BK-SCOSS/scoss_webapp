#include<iostream>
using namespace std;


void result(int T,int *a,int *b)
{
	//cout<<"\n-----------------------------------------";
	for(int i=0;i<T;i++)
	//	cout<<"\n"<<a[i]<<"  "<<b[i]<<"---->"<<a[i]+b[i];
		cout<<a[i]+b[i]<<endl;
	
}

void init(int &T,int *&a,int *&b)
{
	
	do
	{
		cout<<"\nEnter T: ";
		cin>>T;
	}while(T<0||T>10);
	a=new int[T];
	b=new int[T];
	for(int i=0;i<T;i++)
	{
		cout<<"\nEnter a_("<<i+1<<"): ";
		cin>>a[i];
		cout<<"\nEnter b_("<<i+1<<"): ";
		cin>>b[i];
	}
}



int main()
{
	int*a,*b,T;
	init(T,a,b);
	result(T,a,b);
	return 0;
}
