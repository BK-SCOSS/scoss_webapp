#include<iostream>
using namespace std;
int main(){
	int T,j;
	do{
		cin>>T;
	} while(T<=0 || T>10);
	unsigned long long a[10][2];
	for(int i=0;i<T;i++){
		for(j=0;j<2;j++){
			do{
				cin>>a[i][j];
				}while(a[i][j]<0);
			}
		}
	for(int i=0;i<T;i++){
		unsigned long long sum=0;
		for(int j=0;j<2;j++){
			sum=sum+a[i][j];
			}
		cout<<sum<<endl;
		}
	
	return 0;
}
