#include <iostream>	
#include <bits/stdc++.h>
using namespace std;
int kiemtra(int a, int  b){
	int a1= a/1000;
	int a2= a/100-(a/1000)*10;
	int a3= a/10- (a/100)*10;
	int a4= a%10;
	
	int a6= b/100;
	int a7= b/10-(b/100)*10;
	int a8= b%10;
	if(a3==0){ return 0;}
	else{
	
	if((a1==a2)||(a1==a3)||((a1==a6)||a1==a4)||(a1==a7)||(a1==a8)) { return 0;}
	else if((a2==a3)||(a2==a4)||(a2==a6)||(a2==a7)||(a2==a8)) { return 0;}
	else if((a3==a4)||(a3==a6)||(a3==a7)||(a3==a8)) { return 0;}
	else if ((a4==a6)||(a4==a7)||(a4==a8)) { return 0;}
	else if ((a6==a7)||(a6==a8)) { return 0;}
	else if ((a7==a8)) {return 0;}
	 return 1;
	}
  }
	
	

int main(){
	int n;
	cin >> n;
int long long a[n];
int  b[n];
 for(int i=0; i<n; i++){
 	cin >> a[i];
 }
    for(int k=0; k<n; k++){
	  int t=0;
	for(int i=1023; i<9877; i++){
		for(int  j=012; j<988; j++){
		if(((i+j*10+i%10+((i/10)-(i/100)*10)*10000)==a[k])&& (kiemtra(i,j))) {t++;}
		}
	
	}
			b[k]=t;
	}
for(int i=0; i<n; i++){
	cout << b[i];
	cout << endl;
}
	return 0;
}
