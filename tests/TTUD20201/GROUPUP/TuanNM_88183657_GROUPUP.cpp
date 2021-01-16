#include<bits/stdc++.h>

using namespace std;
int t,n;
int a[100001];
int main()
{   
    cin>>t;
    while (t != 0)
        {
            cin>>n;
            for(int i=1; i <= n; i++)
                cin >> a[i];
   
            int res=0;
            int flag=n;
            while (flag != 1)
            {
            int timek=0;
            int i=1;
            if (flag % 2 == 0) 
                {
                flag= flag/2;
               
                
                    for (int j=1; j<= flag *2;j=j+2)
                            {  
                                int k=a[j]+a[j+1];
                                a[i]=k;
                                // cout<< a[i]<< endl;
                                timek=max (timek,a[i]);
                                i++;
                            } 
                    }
                else {
                    flag=flag/2+1;
                        
                        for (int j=1; j<= flag *2-1;j=j+2)
                            {   if  (j== (flag *2-1)) a[i] =a[j]; 
                            else { 
                                a[i]=a[j]+a[j+1];
                                //  cout<< a[i]<< endl;
                                
                               
                                }
                                 
                                timek=max (timek,a[i]);
                                // cout<< a[i]<< endl;
                                i++;
                            }
                }
                // cout<< timek<<endl;
                res += timek; 
            }
            cout<< res <<endl;
            t--;
            }
            
    return 0;
}