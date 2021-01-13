#include <stdio.h>



int main(){
	
int i=1;
int Q,N,N2,a=1,uoc=0;

printf("");scanf("%d",&Q);
do{
    printf("\n");scanf("%d",&N);
    a++;
    N2=N*(N+1)*(N+2);
    for(i=1;i<N2-1;i++){
    	if((N2*N2) % i == 0){
    		uoc++;
		}
	}
	printf("",uoc);
}
while(a<=Q);

return 0;
}
