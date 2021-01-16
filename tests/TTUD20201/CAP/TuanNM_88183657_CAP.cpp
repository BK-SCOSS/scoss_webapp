#include<iostream>

using namespace std;
unsigned long long a[101],b[101];
int c[101]={};
int n,m;
int T;
int main()
{   
    cin>> T;
    if (T==0) cout<< "0" << endl;
    else for (int h=1; h<= T;h++)
    {   
    int k=0;
      cin>>n;
      for (int i=0;i<n;i++)
      cin>>a[i];
      
      cin>>m;
      for (int j=0;j<m;j++)
      cin>> b[j];
      
      for (int i=0 ; i < n; i++)
        for (int j=0; j < m ; j++)
           { 
               if ( a[i]==b[j] && c[i]==0) 
                {
                    k++; 
                    c[i]=1;
                   
                }
           }
        cout<<k<<endl;
        T--;
           
    }
    return 0;
        
}