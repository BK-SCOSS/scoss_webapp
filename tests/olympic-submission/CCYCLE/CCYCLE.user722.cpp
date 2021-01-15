#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define Max 100
int n,L,s,t,result = 0;
vector <int> A[Max];
int x[Max];
void input(){
	cin>>n>>L>>s>>t;
	A[1].push_back(2);
	A[2].push_back(1);
	A[1].push_back(3);
	A[3].push_back(1);
	A[3*n].push_back(1);
	A[1].push_back(3*n);
	for(int i = 1; i < n ; i++){
		A[3*i+1].push_back(3*i); 
		A[3*i].push_back(3*i+1);
		A[3*i+1].push_back(3*i+2);
		A[3*i+2].push_back(3*i+1);
		A[3*i+1].push_back(3*i+3);
		A[3*i+3].push_back(3*i+1);
	}
}


void Try(int k){
	for(int i = 0; i < A[x[k-1]].size();i++){
		int v = A[x[k-1]][i];
		if(k < L){
			x[k] = v;
			Try(k+1);
		}else{
			if(k == L && v == t){
				result++;
			}
		}
	}
}
int main(){
	input();
	x[0] = s;
	Try(1);
	int m=1000000007;
    cout<<(result%m + m) % m;
}
