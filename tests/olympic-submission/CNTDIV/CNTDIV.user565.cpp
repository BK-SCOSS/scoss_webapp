#include <iostream>
using namespace std;

int main(){
	int q,i,j,n[100000],cont;
	long long t[100000];
	cin>>q;
	for(i=0;i<q;i++){cin>>n[i];t[i]=n[i]*(n[i]+1)*(n[i]+2);}
	for(i=0;i<q;i++){
		cont=0;
		for(j=2;j<t[i];j++)if((t[i]*t[i])%j==0&&t[i]%j!=0)cont++;
		cout<<cont<<endl;
	};
	 
}

