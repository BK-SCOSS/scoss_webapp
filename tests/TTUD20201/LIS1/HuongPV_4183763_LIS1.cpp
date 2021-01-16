#include <bits/stdc++.h>
using namespace std;

void Try(int k,int a[], int n, int &cur){
	for(int i=k; i<n; i++){
		if(a[i]==(a[k]+1)){
			cur=cur+1;
			Try(i, a, n, cur);
			break;
		}
	}
}



int main(){
    int T;
    cin>>T;
    for(int t=0; t<T; t++){
    	int ketqua=0;
    	int a[100005];
    	int n;
    	cin>>n;
    	for(int v=0; v<n; v++){
    		cin>>a[v];
		}
		for(int j=0; j<n; j++){
			if((n-j)<=ketqua) break;
			int cur=0;
			Try(j, a, n, cur);
			if(cur>ketqua) ketqua=cur;
		}
		ketqua=ketqua+1;
		cout<<ketqua;
	}
}
