#include <iostream>
using namespace std;
void NhapMang(int a[],int n){
	for(int i= 0; i< n; i++){
		cin >> a[i];
	}
}

void PhanTuGiongNhau(int a[], int b[], int k, int l){
	int dem=0;	
	for(int i=0; i <k; i++){
		for(int j=0; j<k; j++){
			if(a[i]==b[j]){
				dem++;
			}
		}
	}
	cout << dem;
}

int main(){
	int n, k, l;
	int a[k], b[l];
	
	do{
		cin >> n;
	}while(n<0 || n>10);
	
	for(int i=0; i< n; i++){
		cin >> k;
		NhapMang(a, k);
	
		cin >> l;
		NhapMang(b, l);
	
		PhanTuGiongNhau(a, b, k, l);
	}
	
	
}
