#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int T;
	do
	{
		cin>>T;
	}while((T<0)||(T>10));
	int a[T],b[T];
	for(int i=0; i<T; i++)
	{
		cin>>a[i]>>b[i];
    }
    for(int i=0; i<T; i++)
    {
    	cout<<a[i]+b[i]<<"\n";
	}
	return 0;
}
