#include<iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    double s[n];
    double a,b;
    for(int i=0;i<n;i++){
    cin>>a;
    cin>>b; 
    s[i]=a+b; 
    
    }
    for(int i=0;i<n;i++){
    printf("%.0lf\n",s[i]);    
    }
    
}