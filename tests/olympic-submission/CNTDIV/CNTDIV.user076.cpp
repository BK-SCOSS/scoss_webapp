#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int sl;
	cin>>sl;
	unsigned long a[sl];
	unsigned long long t[sl];
	for (int i=0;i<sl;i++)
	cin>>a[i];
	for (int i=0;i<sl;i++)
	t[i]=a[i]*(a[i]+1)*(a[i]+2);
	for (int i=0;i<sl;i++)
	{ int dem=0;
	  for (unsigned long long j=2;j<t[i];j++)
	  {if ((t[i]*t[i])%j==0 && t[i]%j !=0)
	   {dem++;
	   }
	  }
	  cout<<dem<<"\n";
	}
	return 0;
}
