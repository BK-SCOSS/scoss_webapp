#include <iostream>
#include<algorithm>
using namespace std;

int a[1000],b[1000],sum=0,lonnhat=0;
int ham(int n ,int a[]){

    if(n!=1){
                if(n%2 ==0){
                    int x= n/2;
                    int b[x];
                    for(int i = 0 ; i<x;i++){
                        b[i]= a[i*2] + a[i*2 +1];
                    }

                    for(int i = 0 ; i<n ; i++){
                        if(a[i]<a[i+1])
                            lonnhat = a[i+1];
                        else
                            lonnhat = a[i];
                    }
                    sum = sum + lonnhat;

                    return ham(x,b);
               }
               if(n%2 ==1){
                    int x = n/2+1;
                    int b[x];
                    for(int i =0 ; i <x; i++){
                        if(i==x-1) b[i] = a[i*2];
                        else
                        b[i]= a[i*2] + a[i*2+1];
                    }
                    for(int i = 0 ; i<n ; i++){
                        if(a[i]<a[i+1])
                            lonnhat = a[i+1];
                        else
                            lonnhat = a[i];
                    }
                    sum = sum + lonnhat;
                    return ham(x,b);
               }

    }
    if(n == 1)
        return sum;
}
int main()
{

   int T,n;
   cin>>T>>n;
   int a[n],b[n];
   for(int i = 0 ; i <n ; i++){
        cin>>a[i];
   }
   ham(n,a);
}

