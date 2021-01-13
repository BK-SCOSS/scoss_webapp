#include <iostream>
using namespace std;

main(){
	int n,i;
	unsigned long long a[10],b[10],aa,bb;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i]>>b[i];
	for(i=0;i<n;i++){if(a[i]+b[i]>a[i])cout<<a[i]+b[i]<<endl;
		else{
			bb=a[i]%10000000000+b[i]%10000000000;
			aa=a[i]/10000000000+b[i]/10000000000;
			cout<<aa<<bb<<endl;
		}}

}

