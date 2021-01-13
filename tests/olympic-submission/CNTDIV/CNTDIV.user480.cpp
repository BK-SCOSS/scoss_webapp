#include<bits/stdc++.h>
using namespace std;

 int main()
{
   int q,dem=0;
   int *a,*b,c[100];
   float  d[100],e[100];
     cout<<"nhap q:";   cin>>q;
       a=new int[q+1];
	 for(int i=1;i<=q;i++){
	 	cin>>a[i];
	 } 
	 b=new int[q+1];
	 for(int i=1;i<=q;i++){
	 	b[i]=a[i]*(a[i]+1)*(a[i]+2);
	 	cout<<b[i]<<"\n";
	 	c[i]=b[i]*b[i];   cout<<c[i]<<"\n";
	 	for(int j=1;j<=b[i]*b[i];j++){
			    d[j]=1.0*c[i]/j;   cout<<d[j]<<"\t";
			  for(int r=1;r<=b[i];r++)  
			  if(b[i]%r==0)  e[j]=b[i]/r;  
			  if(c[i]%j==0&&d[j]<b[i]&&d[j]!=e[j])	
			     dem++;
		 }
	     cout<<dem;
	 }
	 
}

