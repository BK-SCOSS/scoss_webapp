#include<iostream>
using namespace std;

int tosum(int a){
	int s=0;
	long long t = a*(a+1)*(a+2);
	long long T = t*t;
	for(int i=2;i<t;i++)
		if(T%i==0&&t%i!=0) s++;
	return s;
}
int main(){
	int a; cin >> a;
	int arr[a],x;
	for(int i=0;i<a;i++){
		cin >> x;
		arr[i] = tosum(x);
	} for(int i=0;i<a;i++)
		cout << arr[i];
	return 0;
}
