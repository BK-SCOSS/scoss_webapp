#include <bits/stdc++.h>

using namespace std;

int n,a[9],d[10],t,res;

bool check(){
    int t = a[1]*1000+a[2]*100+a[3]*10+a[4]+a[3]*10000+a[5]*1000+a[6]*100+a[7]*10+a[4];
	return t == n;
}

void TRY(int x){
    if(x == 8) {
        if(check()){
        	res++;	
		}
		return;
        
    }
    for(int i = 0; i <= 9; i++){
        if(d[i]==0){
            d[i] = 1;
            a[x] = i;
            TRY(x+1);
            d[i] = 0;
        }
    }
}

int main()
{
    cin >> t;
    for(int i=0;i<t;i++){
    	cin>>n;
    	res=0;
    	TRY(1);
    	cout << res<<endl;
	}
    return 0;
}
