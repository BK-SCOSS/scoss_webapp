#include <iostream>

using namespace std;

int main()
{
    int n,m,T,x,flag=0;
    cin>>T;
    cin>>n;
    int a[n];
    for(int i = 0; i < n ; i++){
        cin>>a[i];
    }
    cin>>m;
    int b[m];
    for(int j = 0 ; j < m ; j++){
        cin>>b[j];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i]==b[j]){
                flag= flag +1;
                b[j]=0;
            }

        }
    }
    cout<<flag;
}

