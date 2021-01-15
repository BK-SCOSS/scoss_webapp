#include<stdio.h>
#include<math.h>
main()
{
	int q,t,u,s;
	scanf("%d\n",&q);
	int n[q-1];
	for(int i=0;i<q;i++){
		scanf("%d\n",&n[i]);
	}
	int dem[q-1][1000000];
	for(int j=0;j<q;j++){
	
	for(int u=n[j];u<=n[j]+2;u++){
		for(int i=2;u>0;i++){
			if(u%i==0){
				dem[j][i]+=1;
				u=u/i;
			}
		}
	}}
	for(int j=0;j<q;j++){
	
	for(int i=1;i<=n[j]+2;i++) s=s*(dem[j][i]+1);
     for(int i=1;i<=n[j]+2;i++) t=t*(2*dem[j][i]+1);
	 printf("%d\n",(t-1)/2-s+1);}
	 return 0;	
}
