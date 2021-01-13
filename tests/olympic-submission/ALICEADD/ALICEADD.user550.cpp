#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int boSoLieu = 0;
	unsigned long long int a[10], b[10];
	cin >> boSoLieu;
	for (int i = 0; i < boSoLieu; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < boSoLieu; i++) {
		if(b[i]>18446744073709551615-a[i]){
			unsigned long long int x1 = a[i]/1000000000;
			unsigned long long int x2 = a[i]-x1*1000000000;
			unsigned long long int y1 = a[i]/1000000000;
			unsigned long long int y2 = a[i]-x1*1000000000;
			unsigned long long int tong2 = x2+y2;
			unsigned long long int tong1 = x1+y1;
			if(tong2>=1000000000){
				tong2 -= 1000000000;
				tong1 ++;
			}
			cout << tong1<<tong2;
		}
		else cout << a[i] + b[i] << endl;
	}
}
