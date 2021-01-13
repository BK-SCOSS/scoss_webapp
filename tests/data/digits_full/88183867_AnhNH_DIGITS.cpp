#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 1000000

using namespace std;

int main(){
	int n;
	cin>>n;
	string a;
	int C[n],H[n];
	int coutC=n,coutH=0;
	for(int i=0;i<n;i++){
		cin>>C[i];
		}
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]=='C') {
		      H[coutH]=C[coutC-1];
		      coutH++;
		      coutC--;
		} 
		if(a[i]=='H') {
		C[coutC]=H[coutH-1];
		coutC++;
		coutH--;
		}
		}
	for(int i=0;i<n;i++){
		cout<<C[i]<<" ";
		}
	
	}
