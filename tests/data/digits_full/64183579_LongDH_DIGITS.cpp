#include<bits/stdc++.h>
using namespace std;
int t;
long long n,res;
bool visited[10];
int a[7];
long long check(){
	long long t= a[0]*1000+a[1]*100+a[2]*10+a[3] + a[2]*10000+ a[4]*1000+a[5]*100+a[6]*10 +a[3];
	return t;
}

bool ucv(int k, int i){
	if(visited[i]) return false;
	if(k==0 && i==0) return false;
	if(k==2 && i==0) return false;
	return true;
}

void Try(int k){
		for(int i=0;i<=9;i++){
			if(ucv(k,i)){
				visited[i]=true;
				a[k]=i;
				if(k==6){
					if(check()==n) res++;
				}
				else Try(k+1);
				visited[i]=false;
			}
		}


}

int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		for(int i=0;i<7;i++) visited[i]=false;
		cin >> n;
		res=0;
		Try(0);
		cout<<res<<endl;	
	}
	return 0;
}

