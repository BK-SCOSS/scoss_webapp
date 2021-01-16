#include<bits/stdc++.h>
using namespace std;

int t;
int n;
// int dequy(int a[],int n){
//     int res =0;
//     if(n!=1){
//     while(n!=1){
//         if(n%2==1){
//             int max1=0;
//             int temp=a[n];
//             for(int i=1;i<n;i=i+2){
//                 a[i/2+1]=a[i]+a[i+1];
//                 max1 = max1>a[i/2+1] ? max1 : a[i/2+1];
//             }
//             a[n/2+1]=temp;
//             res=res+max1;
//             n=n/2;
//         }
//         else{
//             int max2=0;
//             for(int i=1;i<=n;i=i+2){
//                 a[i/2+1]=a[i]+a[i+1];
//                 max2 = max2>a[i/2+1] ? max2 : a[i/2+1];
//             }
//             res=res+max2;
//             n=n/2;

//         }
//     }}
//     else return res+a[1]+a[2];
// }

int main(){
    cin>>t;
    while(t--){
    cin>>n;
    int a[2*n+1][2*n+1];
        for(int i=1;i<=2*n+1;i++){
        for(int j=1;j<=2*n+1;j++){
            a[i][j]=0;
        }
    }
    int k=0;
    for(int i=1;i<=n;i++){
        if((n-pow(2,i)<=0)){
            k=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[1][i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j=j+2){
            a[i+1][j/2+1]=a[i][j]+a[i][j+1];
        }
    }
    int max1[n];
    for(int i=1;i<=n;i++){
        max1[i]=0;
    }
    int res=0;
    for(int i=2;i<=k+1;i++){
        for(int j=1;j<=n;j++){
            max1[i]=max(max1[i],a[i][j]);
        }
        res = res + max1[i];
    }
    //     for(int i=1;i<=k+1;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;

    // }
    cout<<res;
    }
}