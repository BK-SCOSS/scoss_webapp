#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Cong(unsigned long long a,unsigned long long b)
{ int m[20];
  int n[20];
  int tong[21];
  int scsa=0,scsb=0;
  int scstong;
  while (a>0)
  {m[scsa]=a%10;
   scsa++;
   a=a/10;
  }
  while (b>0)
  {n[scsb]=b%10;
   scsb++;
   b=b/10;
  }
  if (scsa>=scsb)
  {for (int i=scsb+1;i<scsa;i++) n[i]=0;
   for (int i=0;i<=scsa;i++) tong[i]=0;
   for (int i=0;i<scsa;i++)
   { tong[i]=tong[i]+m[i]+n[i];
     if (tong[i]>=10)
     {tong[i]=tong[i]-10;
      tong[i+1]++; 
	 }
   }
   if (tong[scsa]==0)
   {for (int i=scsa-1;i>=0;i--) cout<<tong[i];}
   else
   {for (int i=scsa;i>=0;i--) cout<<tong[i];}
  }
  else
   {for (int i=scsa+1;i<scsb;i++) m[i]=0;
   for (int i=0;i<=scsb;i++) tong[i]=0;
   for (int i=0;i<scsb;i++)
   { tong[i]=tong[i]+m[i]+n[i];
     if (tong[i]>=10)
     {tong[i]=tong[i]-10;
      tong[i+1]++; 
	 }
   }
   if (tong[scsb]==0)
   {for (int i=scsb-1;i>=0;i--) cout<<tong[i];}
   else
   {for (int i=scsb;i>=0;i--) cout<<tong[i];}
  }
}
int main(int argc, char** argv) {
	int n;
	cin>>n;
	unsigned long long a[n][2];
	for (int i=0;i<n;i++) cin>>a[i][1]>>a[i][2];
	for (int i=0;i<n;i++)
	{Cong(a[i][1],a[i][2]);
	cout<<endl;}
	return 0;
}
