#include<bits/stdc++.h>
using namespace std;

int n, T;
int a[11000];
int f[11000];
int rs[100];

int best = 0;
int main(){
	cin >> T;
	int t0=T;
	while(T>0){
		T--;
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> a[i];
		}
		for(int i = n;i>0;i--){
			f[i]=1;
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]-1){
					f[i]=max(f[i],f[j]+1);
				}
			}
		}
		for(int i = 1; i<=n;i++){
			best = max(best,f[i]);
		}
		rs[T+1]=best;
	}
	for(int i=t0;i>0;i--){
		cout<<rs[i]<<endl;
	}
}
