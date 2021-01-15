#include <iostream>
using namespace std;
int dem(long long x,long y){
	int dem=0;
	for (int i=1;i<y;i++){
		if(x%i==0&&y%i!=0) dem++;
	}
	return dem;
}
int main(){
	int m;
	cin>>m;
	long *a,*b;
	a=new long[m];
	b=new long[m];
	for (int i=0;i<m;i++){
	cin>>a[i];
	long t=a[i]*(a[i]+2)*(a[i]+1);
	b[i]=dem(t*t,t);
	}
	for (int i=0;i<m;i++){
		cout<<b[i]<<endl;
	}
	delete []b;
	delete [] a;
	return 0;
}
