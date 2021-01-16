#include <iostream>
using namespace std;
int a[100000];
int n;
int main(){
    int t;
    cin>>t;
    for (int j=1;j<=t;j++){
        cin>>n;
        for (int i=0;i<=n-1;i++) scanf("%d",&a[i]);
        long long int r=0;
        while (n>1){
            long long int m=0;
            for (int k=0;k<=n-1;k+=2){
                long long int t=0;
                if (k<n-1) t=a[k]+a[k+1]; else t=a[k];
                m=max(m,t);
                a[k/2]=t;
            }
            r+=m;
            if (n%2==0) n/=2; else n=n/2+1;
        }
        cout<<r<<endl;
    }
}