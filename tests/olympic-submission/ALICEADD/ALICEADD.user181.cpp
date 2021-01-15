#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n>10){
		cin>>n;
	}
	unsigned long long a[n][2];
	for (int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for (int i=0;i<n;i++){
		unsigned long long c=a[i][0]+a[i][1];
		cout<<c<<endl;
		}
		return 0;
	}
