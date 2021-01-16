#include <iostream>
using namespace std;
int nhap(int a[],int n){
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
int main(){
	int T,dem,c[10000];
	cin>>T;
	dem=0;
	for (int i=0;i<T;i++){
	int n,m;
	int a[10000],b[10000];
	cin>>n;
	nhap(a,n);
	cin>>m;
	nhap(b,m);
	int count=0;
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (a[i]==b[j]){
				count++;
			}
		}
	}
	c[dem]=count;
	dem++;
}
	for(int i=0;i<dem;i++){
		cout<<c[i]<<endl;
	}
}
