#include<iostream>
#include<algorithm>
using namespace std;

int a[100],b[100],n,m;
int T(int t){
   int count = 0;
   int*p;
	  cin >> n;
	  for(int i=0;i<n;i++){
	 	cin >>a[i];
	  }
	  cin >>m;
	  for(int i=0;i<m;i++){
		cin >>b[i];
	   }  	
	  for(int i=0;i<n;i++){
		p=find(b,b+m,a[i]);
		if(p !=b+m){
			count = count+1;
			}
	}
	cout << count;

}
int main(){
	int t;
	cin >>t;
	T(t);
}

