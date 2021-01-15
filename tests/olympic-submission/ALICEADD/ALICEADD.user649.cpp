#include<iostream>
using namespace std;
int main(){
	int T,a,b,dem=0,i;
	int *c=new int(T);
	
	cin>>T;
	while(T>0){
		cin>>a;
		cin>>b;
		c[dem]=a+b;
		T-=1;
		dem+=1;
	}
	for(i=0;i<dem;i++){
		if(i!=(dem-1)) cout<<c[i]<<"\n";
		else cout<<c[i];
	}
	return 0;
}
