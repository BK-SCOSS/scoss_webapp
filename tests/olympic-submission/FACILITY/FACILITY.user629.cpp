#include<iostream>
using namespace std;

int main()
{
    long int n,k;
    cin>>n;
    cin>>k;
    long int s[n],d[n],r[n];
    long int Se[n],Sr[n],Ss[n];
    long int rs_e,rs_r,rs_s;
    for(int i=0;i<n;i++){
    cin>>s[i];
    cin>>d[i];
    cin>>r[i];   
    }
    long int temp;
    for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
    if(s[i]>s[j]){
     temp=s[j];
     s[j]=s[i];
     s[i]=temp;
     temp=d[j];
     d[j]=d[i];
     d[i]=temp;
     temp=r[j];
     r[j]=r[i];
     r[i]=temp;   
    }
    }}
    
    
    
    
    
    
    Ss[0]=s[0];
    Se[0]=s[0]+d[0]+k;
    Sr[0]=r[0];  
    rs_e=Se[0];
    rs_s=Ss[0];
    rs_r=Sr[0];
    for(int i=1;i<n;i++){
     Ss[i]=s[i];
     Se[i]=s[i]+d[i]+k;
     Sr[i]=r[i];
     for(int j=i-1;j>=0;j--){
    if(Ss[i]>=Se[j]){
      if((r[i]+Sr[j])>Sr[i] ){
      Sr[i]=r[i]+Sr[j];
    
    
    } 
    }
    }
    if(Sr[i]>rs_r){
     rs_r=Sr[i];
   
    }
    
    }
    printf("%ld",rs_r);
    return 0;
}