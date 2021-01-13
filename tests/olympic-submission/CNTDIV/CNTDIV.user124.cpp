#include<stdio.h>
#include<math.h>
int main()
{
    
    int q;
    scanf("%d",&q);
    int N[q];
    int T[q];
    int kq[q]{0};
    for(int i =0;i<q;i++){
    	scanf("%d",&N[i]);
    	T[i]=N[i]*(N[i]+1)*(N[i]+2);
	}
    
    for(int i =0;i<q;i++){
    	for(int j=2;j<T[i];j++)
    	if(((T[i]*T[i])%j) ==0 && (T[i]%j) !=0)
    	kq[i]++;
	}
    
    for(int i=0;i<q;i++)
    printf("%d",kq[i]);
    
    return 0;
    
}
