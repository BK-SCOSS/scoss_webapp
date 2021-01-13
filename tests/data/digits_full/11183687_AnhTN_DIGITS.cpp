#include<bits/stdc++.h>
using namespace std;

int x[7];//7 chu cai h u s t o i c
bool visited[10]; 
long long n,counts[100];
long long N[100];
void getSolution(){
	for(long long k=0;k<n;k++){
		long long T=x[0]*1000+x[1]*100+x[2]*10+x[3]+x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3];
		if(T==N[k]) counts[k]++;
	}
	
}
void Try(long long k){
	for(int v=0;v<=9;v++){
		if((!visited[v])){
			if((x[0]!=0)&&(x[2]!=0)){
			x[k]=v;	
			visited[v]=true;
			if(k==6) getSolution();
			else Try(k+1);
			visited[v]=false;				
			}
		}
	}
}
int main(){
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>N[i];
		Try(0);
	}
	for(long long i=0;i<n;i++){
		cout<<counts[i]<<endl;
	}
	return 0;
}
