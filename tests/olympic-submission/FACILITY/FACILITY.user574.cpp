#include <bits/stdc++.h>
using namespace std;

void Swap(int *a, int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int main()
{
    int n,k,max1;
    cin>>n>>k;
    int A[n],B[n],C[n],L[n];
    for (int i=0;i<n;i++) cin >>A[i]>>B[i]>>C[i];
    for (int i=0;i<n;i++) B[i]+=A[i];
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
              if (B[i]>B[j]){
             Swap(&A[i],&A[j]);
             Swap(&B[i],&B[j]);
             Swap(&C[i],&C[j]);
       }
    }
    for (int i=0;i<n;i++)
   {
          L[i]=C[i];
          for (int j=0;j<i;j++)
               if (B[j]+k<=A[i] && L[i]<L[j]+C[i]) L[i]=L[j]+C[i];
   }
   max1=L[0];
   for (int i=0;i<n;i++){
      if (max1 < L[i]) max1=L[i];
   }
   cout <<max1;
   return 0;
}

