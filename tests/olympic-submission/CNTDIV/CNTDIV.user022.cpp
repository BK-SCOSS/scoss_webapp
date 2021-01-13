#include <iostream>

using namespace std;

int main()
{
    long long int q,i,j;
    do
    {
     cin>>q;
    }while(q<0);
    long long int a[q],b[q],c[q];
    for(i=0;i<q;i++) c[i]=0;
    for(i=0;i<q;i++)
    {
        cin>>a[i];
        b[i]=a[i]*(a[i]+1)*(a[i]+2);
    }
    for(i=0;i<q;i++)
      for(j=1;j<b[i];j++)
	     {
	     	if(((b[i]*b[i])%j==0)&&(b[i])%j!=0)
	     	   c[i]++;
			 }
	for(i=0;i<q;i++)
	   cout<<c[i]<<endl;		     
    return 0;
}
