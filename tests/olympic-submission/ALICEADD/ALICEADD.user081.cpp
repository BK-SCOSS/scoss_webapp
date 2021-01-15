#include<stdio.h>
#include<math.h>
main ()
{
	int sobo;
	do{
		scanf("%d\n",&sobo);
	}
	while (sobo<1||sobo>10);
	int a[sobo],b[sobo],c[sobo];
	for (int i=0;i<sobo;i++)
	{
		do{
		scanf("%d %d\n",&a[i],&b[i]);}
		while (a[i]<=0|| b[i]<=0);
		c[i]=a[i]+b[i];
		
	}
	for(int i=0;i<sobo;i++){
		printf("%d\n",c[i]);
	}
	return 0;
}
