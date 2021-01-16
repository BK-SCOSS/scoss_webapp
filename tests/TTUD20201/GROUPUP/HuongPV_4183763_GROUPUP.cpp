#include<bits/stdc++.h>
using namespace std;

int max_arr(int a[], int start, int end){
	int max=0;
	for(int i=start; i<end; i++){
		if(max<a[i]) max=a[i];
	}
	return max;
}

void hopnhat(int a[], int n, int &ketqua){
	int time;
	if(n==1) return;
	int b[10005];
	for(int i=0; i<n; i=i+2){
		b[i/2]=a[i]+a[i+1];
	}
	if(n%2==0){
		time=max_arr(b,0,n/2);
		ketqua=ketqua+time;
		hopnhat(b,n/2,ketqua);
	}
	if(n%2==1){
		time=max_arr(b,0,n/2);
		ketqua=ketqua+time;
		b[n/2]=a[n-1];
		hopnhat(b,n/2+1,ketqua);
	}
}

int main(){
	int T;
	cin>>T;
	for(int t=0; t<T; t++){
		int n;
		int ketqua=0;
		int a[10005];
		cin>>n;
		for(int v=0; v<n; v++){
			cin>>a[v];
		}
		hopnhat(a,n,ketqua);
		cout<<ketqua;
		
	}
	
}
