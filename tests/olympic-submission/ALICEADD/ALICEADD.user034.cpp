#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int a;
	int sum[200];
	int b[200],c[200];
	cin>>a;
	for (int i=0; i<a;i++){
		cin>>b[i]>>c[i];
	}
	for (int i=0; i<a; i++){
		sum[i]=b[i]+c[i];
		cout<<sum[i]<<endl;
	}
	return 0;
}
