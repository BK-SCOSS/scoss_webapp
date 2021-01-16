#include <bits/stdc++.h>
using namespace std;
int a[1000], n,t;
int mem[1000]; 

void init(){
    memset(mem, -1, sizeof(mem));
}

int LIS(int i) {
    if(mem[i]!=-1){
    	return mem[i];
	}
	int kq=1;
	for(int j=0;j<i;j++){
		if(a[j]<a[i]&&(a[i]-a[j])==1){
			kq=max(kq,1+LIS(j));
			
		}
	}
	mem[i]=kq;
	return kq;
}

int main(){
	cin>>t;
	for(int k=0;k<t;k++){
	
    init();
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < LIS(i)){
            res = LIS(i);
            pos = i;
        }
    }
    cout << res << endl;
	}
    return 0;
}
