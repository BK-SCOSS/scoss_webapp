#include <bits/stdc++.h>
using namespace std;

int x[7]; // x[0]=H x[1]=U x[2]=S x[3]=T x[4]=O x[5]=I x[6]=C
bool visited[10];
int rs,T, N;

void solution(){
	int t=x[0]*1000+x[1]*100 + x[2]*10 + x[3] + x[2]*10000 + x[4]*1000 + x[5]*100 + x[6]*10 + x[3];
	if(t==N) {
		rs++;
	}
}
void init(){
	for(int i=1;i<=9;i++) visited[i]=false;
}
bool check(int v, int k){
	if(visited[v]) return false;
	if(k==0|| k==2) return v!=0;
	return true;
}
void TRY(int k){
	for(int v=0;v<=9;v++){
	if(check(v,k)){
		x[k]=v;
		visited[v]=true;
		if(k==6) solution();
		else TRY(k+1);
		visited[v]= false;
		
	 }
	}
}
main(){
	cin >> T;
//	cout << T << endl;
	while(T>0){
//		cout << "T: "<<T << endl;
		cin >> N;
		init();
		rs=0;
		TRY(0);
		cout << rs << endl;
		T--;
	}
}
