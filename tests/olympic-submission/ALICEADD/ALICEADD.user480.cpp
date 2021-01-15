#include<bits/stdc++.h>
using namespace std;

 int main()
{
    int t;
    int a[10],b[10];
         cin>>t;
       if(t>0&&t<=10){
          	for(int i=1;i<=t;i++)
          	  {
          	  	  cin>>a[i]>>b[i];
				}
			for(int i=1;i<=t;i++)
			   cout<<a[i]+b[i]<<"\n";
       }
        else
          {
              return 0; 
		  }
		  
}

