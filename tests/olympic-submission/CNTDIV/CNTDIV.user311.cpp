#include <iostream>
using namespace std;


int main() {
    int q;
	do{
		cin >> q;
	}
	while(q<=0);
	int i;
	for(i=0;i<q;i++){
	int j;
	int a,b;
	cin >> a;
	b=a*(a+1)*(a+2);
	int x;
	x=b*b;
	int count=0;
	for(j=1;j<b;j++){
		if( x%j == 0){
			count++;
		}
	}
	int dem=0;
	for(j=1;j<=b;j++){
		if( b%j ==0){
			dem++;
		}
	}
	int Hieu=count-dem+1;
	cout << Hieu <<endl;
	}
	return 0;
}
