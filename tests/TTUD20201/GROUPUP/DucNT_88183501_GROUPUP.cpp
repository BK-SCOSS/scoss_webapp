#include<bits/stdc++.h>
using namespace std;
int n,t,res,sum;
int a[100005];
int b[100005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		res=0;
		sum=0;
		memset(a,0 , sizeof(a));
		memset(b,0 , sizeof(b));
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		int k=n;
		while(k>1){
		
			memset(b,0 , sizeof(b));
			for(int l=2;l<=k+1;l+=2){
				int d=l/2;
				b[d]=a[l]+a[l-1];
				res=max(res,b[d]);
			}
			sum+=res;

			memset(a,0 , sizeof(a));
			for(int l=1;l<=k;l++){
				a[l]=b[l];
			}
			
			if(k%2){
				k=k/2+1;
			}else{
				k=k/2;
			}
		}	
		cout<<sum<<endl;
	}
		
	return 0;
}
