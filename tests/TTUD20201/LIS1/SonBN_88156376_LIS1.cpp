#include <iostream>

using namespace std;

void DayConDaiNhat(int a[], int n){
	int dem=1;
	int tmp=1;
	int b[n];
	for(int i=0; i< n; i++){
		for(int j =i+1; j< n; j++){
			if(a[i]==a[j]-tmp){
				dem++;
				tmp++;
			}
		}
		b[i]=dem;
	}
	int max=0;
	for(int i=0; i< n; i++){
		if(b[i]>max){
			max=b[i];
		}
	}
	cout << max;
}
void nhapMang(int a[], int n){
	for(int i=0; i<n; i++){
		cin >>a[i];
		
	}
}
int main(){
	int n, k;
	cin >> n;
//	do{
//		cin >> n;
//	}while(n<0||n>10);
//	
//	for(int i=0; i<n; i++){
		cin >>k;
		int a[k];
		nhapMang(a, k);
		DayConDaiNhat(a, k);
//	}
}
