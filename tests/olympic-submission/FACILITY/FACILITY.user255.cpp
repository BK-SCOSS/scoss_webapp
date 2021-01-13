#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	int s;
	int d;
	int r;
}customer;

bool operator < (customer  &k1, customer  &k2)  {
    return k1.s < k2.s;
}
int n,k;
customer* khach;
//bool* choose;
int releaseDate=0;
int sum=0;
int result=0;
int lastDate;
double best=0;



void Try(int i) {
	//chon khach i
	if (releaseDate<=khach[i].s){
		sum+=khach[i].r;
		int tempDate=releaseDate;
		releaseDate=khach[i].s+khach[i].d+k;
		if (sum>result) result=sum;	
			
		if (i<n-1) {
			if(sum+(lastDate-releaseDate)*best>result) Try(i+1);
		}

//			if (k==(n-1)) {
//				if (sum>result) result=sum;
//			}
//			else Try(k+1);
		
		sum-=khach[i].r;
		releaseDate=tempDate;		
	}
	//khong chon khach i
	if (i<n-1)	Try(i+1);
}

int main(int argc, char** argv) {
	cin >>n>>k;
//	choose= new bool[n];
	khach= new customer[n];
	
	for (int i=0;i<n;i++) {
		cin>>khach[i].s>>khach[i].d>>khach[i].r;
//		choose[i]=false;
		if (best<((double) khach[i].r)/khach[i].d) best=((double) khach[i].r)/(khach[i].d+k);
	}
	sort(khach,khach+n);
	lastDate=khach[n-1].s+khach[n-1].s+k;
//	for (int i=0;i<n;i++) {
//		cout<< khach[i].s<<"\n";
//	}
	Try(0);
	cout<<result;
	return 0;
}
