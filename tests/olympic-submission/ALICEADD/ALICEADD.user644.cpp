#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
	unsigned long long int a[10],b[10],c[10];
    cin >>t;
    for(int i=0;i<t;i++){
		cin >>a[i] >>b[i];
		c[i]=a[i]+b[i];
	}
    for (int i=0;i<t;i++)
	    cout <<c[i]<<"\n";
	return 0;
}