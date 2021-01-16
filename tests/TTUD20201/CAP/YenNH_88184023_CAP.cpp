#include<bits/stdc++.h>
using namespace std;

int T[100], a[100], b[100], m, n, mem[100], mem1[100];

int Giao(int n, int a[], int m, int b[] ){
	int dem=0;
	for(int i=0; i<n; i++) 
	  for(int j = 0; j<m; j++)
	  if((a[i]==b[j]) && (mem[j]==0) && (mem1[i]==0)) {
	  	dem++; mem[j]=1; mem1[i]=1;
	  }
	  return dem;
	}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int x;
    cin>>x;
    for(int j = 0; j<x; j++) {
    	cin>>n;
    	for (int i = 0; i<n; i++) cin>>a[i]; 
    	cin>>m; 
    	for (int i = 0; i<m; i++) cin>>b[i]; 
    	memset(mem,0,sizeof(mem));
    	memset(mem1,0,sizeof(mem1));
    	T[j]=Giao(n,a,m,b); 
	}
	for(int i = 0; i<x; i++) cout<<T[i]<<endl;
	return 0;
}

