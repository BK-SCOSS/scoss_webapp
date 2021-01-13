#include<stdio.h>


unsigned int T;
unsigned int N;
int x[7];
int visited[10];
int ans;

void solution(){
	unsigned int m=x[0]*1000+x[1]*100+x[2]*10+x[3]+x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3];
	if(m==N && x[0]!=0 && x[2]!=0){
		ans++;
	}
}
void init(){
	for(int i=0; i<=9; i++){
		visited[i]=0;
	}	
}

void Try(int k){
	for(int i=0; i<=9; i++){
		if(visited[i]==0){
			x[k]=i;
			visited[i]=1;
			if(k==6){
				solution();
			}else{
				Try(k+1);
			}
			visited[i]=0;
		}
	}	
}

int main(){
		scanf("%d",&T);
		while(T--){
			scanf("%d",&N);
			init();
			ans=0;
			Try(0);
			printf("%d \n",ans);
		}
		
	return 0;
}
