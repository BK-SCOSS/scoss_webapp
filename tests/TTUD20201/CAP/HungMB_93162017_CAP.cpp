#include<bits/stdc++.h>
using namespace std;

int na, nb, T;
int a[110], b[110];
int cnt[20];
int main(){
	cin >> T;
	int T0=T;
	while(T>0){
		T--;
		cin>>na;
		for(int i=1;i<=na;i++){
			cin >> a[i];
		}
		cin >> nb;
		for(int i=1;i<=nb;i++){
			cin >> b[i];
		}
		for(int i=1;i<=na;i++){
			for(int j=1;j<=nb;j++){
				if(a[i]==b[j]){
					cnt[T]++;
					break;
				}
			}
		}
	}
	for(int i=T0;i>0;i--){
		cout<<cnt[T]<<endl;
	}
}
