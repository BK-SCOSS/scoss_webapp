#include<iostream>
#include<algorithm>
using namespace std;

int a[100],b[100],n,c=0,m;
int T(int t){
   for(int i=0;i<t;i++){
   int count = 0;
	  cin >> n;
	  for(int i=0;i<n;i++){
	 	cin >>a[i];
	  }
	if(n==1) c=a[0];
	while(n==1){
	  n=n/2;
	  for(int i=0;i<n;i++){
	  	a[i]=a[2*i]+a[2*i+1];
	  }
	  c=c+a[*max_element(a,a+n)];
		
}
}
}
int main(){
	int t;
	cin >>t;
	T(t);
}

