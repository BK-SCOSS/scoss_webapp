#include <iostream>
#include <stdio.h>


using namespace std;

int main(){
	int *n;
	int num;
	int*t,*x, *count;
	cin>>num;
	t =new int[num];
	x =new int[num];
	n =new int[num];
	count =new int[num];
	for(int j=0;j<num;j++){
		count[j]=0;
	}
	for(int j=0;j<num;j++){
	cin>>n[j];
	t[j]=n[j]*(n[j]+1)*(n[j]+2);
	x[j]=t[j]*t[j];
	for (int i=1; i<t[j]; i++){
		if (x[j]%i==0 && t[j]%i==0){
			continue;
		}
		else if ((x[j]%i==0) && ((t[j]%i)!=0)){
			count[j]=count[j]+1;
		}
	}
	}
	for (int j=0;j<num;j++){
	cout<<count[j]<<endl;}
}

