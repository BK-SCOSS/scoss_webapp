#include<bits/stdc++.h>
using namespace std;
int ans,T,d;
int x[7];
unsigned long long N[50];
int app[10];
void sol(){
	if ((x[0]!=0)&&(x[1]!=0)){
	int h=x[0]*1000+x[1]*10010+x[2]*100+x[3]*2+x[4]*1000+x[5]*100+x[6]*10;
	if (h==N[d]) ans++;}
}
void chuso(){
	for (int k=0;k<=9;k++)
	app[k]=0;
}
void TRY(int a){
	for (int k=0;k<=9;k++)
	{
		if (app[k]==0){
			x[a]=k;
			app[k]=1;
			if(a==6)sol();
			else TRY(a+1);
			app[k]=0;
		}
	}
}
int main(){
	cin>>T;
	for(d=0;d<T;d++) cin>>N[d];
	for(d=0;d<T;d++)
	{
    chuso();
    ans = 0;
    TRY(0);
    cout<<ans<<endl;}
    return 0;
}
