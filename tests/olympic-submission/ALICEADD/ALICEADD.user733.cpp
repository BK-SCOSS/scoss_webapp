#include<iostream>

using namespace std;

main() {
	int i, n;
	cin>>n;
	unsigned long long a[10], b[10];
	for (i=0;i<n;i++) cin>>a[i]>>b[i];		
	for (i=0;i<n;i++) 
	{
		if (a[i]+b[i]<=a[i]) cout<< (a[i]/1000000000+b[i]/1000000000)/10 <<(a[i]%100000000000+b[i]%10000000000)%10000000000<<endl;
		else cout << a[i]+b[i] << endl;
	}
//	cout<<a[n-1]+b[n-1];
}
