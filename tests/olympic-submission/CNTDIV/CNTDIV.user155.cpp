#include<iostream>
using namespace std;
int main(){
	int q,j,a,k,c[100];
	unsigned long int t,bp;
	cin>>q;
	for( k=0; k<q; k++){
		cin>>a;
		t=a*(a+1)*(a+2);
		j=0;
		bp=t*t;
		for (int i=2; i<t; i++){
			if (bp%i==0 && t%i!=0 ) {
				j++;
			}
		}
	c[k]=j;
	j=0;
	}
	for (int i=0; i<q; i++) cout<<c[i]<<endl;
	return 0;
}

