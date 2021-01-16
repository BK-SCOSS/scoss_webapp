#include <iostream>

using namespace std;


int main()
{

   int T,n,sum=0,lonnhat = 0;
   cin>>T>>n;
    int a[n],b[n];
   for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
   }


    for(int i = 0 ; i < n ; i ++){
        for(int o = 0 ; o< n ; o ++){
            b[o]=a[o];
        }
        for(int j = i + 1 ; j <n ; j ++){
            if(b[j]-b[i]==1){
                sum = sum + 1;
                b[i]= b[j];
            }
        }

        if(lonnhat<sum) lonnhat = sum;
        else lonnhat= lonnhat;
        sum=0;

    }
    cout<<lonnhat+1;
}

