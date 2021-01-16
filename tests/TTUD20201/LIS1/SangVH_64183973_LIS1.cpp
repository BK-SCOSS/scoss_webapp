#include<iostream>

using namespace std;


int main(){
	int T;
	cin>> T;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	int cou;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(a[i]==b[j]) cou++;
		}
	
	cout<<cou;	
}
