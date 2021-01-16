#include <iostream>
using namespace std;
void nhap(int a[], int n){
	for (int i= 0; i< n; i++){
		cin >> a[i];
	}
}
int max(int a[], int n){
	int max=0;
	for (int i= 0; i< n; i++){
		if(max<a[i]){
			max= a[i];
		}
	}
	return max;
}

int tong=0;
//0 1 2 3
int thoigian(int a[],int n){
	int b[n];
	int bi=0;
//	cout << tong<< endl;
	if(n%2!=0) {
		b[bi+1]= a[n];
		n= n-1;
	}
	for (int i= 0; i< n; i++){
		b[bi]= a[i]+a[i+1];
		bi++;
		i++;
	}
//	cout << bi <<endl;
	if(bi<2) {
		return (tong = tong + b[0]+b[1]);
	}else{
		tong= tong + max(b, bi);
	return thoigian(b, bi+1);
	}
	
	
}
int main(){
	int n;
	int k;
	int l;
	cin>> n;
	
	cin>> k;
	int a[k];
	nhap(a, k);	
	thoigian(a, k);
	cout << tong;
}
