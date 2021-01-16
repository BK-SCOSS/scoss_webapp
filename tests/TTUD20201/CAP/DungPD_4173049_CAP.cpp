#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int check(int *a,int index){
	int res = 1;
	if(index==0) return 1;
	else {
		for(int i=0;i<index;i++){
			if(a[i]==a[index]){
				res = 0;
				break;
			}
		}
	}
	return res;
}
int main(){
	int biendem ;
	int R ;
	cin >> R;
	int u,v;

	for(int j=1;j<=R;j++){
		biendem = 0;
		cin >> u;
		int a[u];
		for(int j=0;j<u;j++){
			cin >> a[j];
		}
		cin >> v;
		int b[v];
		for(int j=0;j<v;j++){
			cin >> b[j];
		}
		for(int l = 0;l<u;l++){
			if(check(a,l)){
				for(int k = 0; k<v;k++){
					if(a[l] == b[k]&&check(b,k)){
						biendem +=1;
						break;
					}
				}
			}
		}
		cout << biendem << endl;
	}

}
