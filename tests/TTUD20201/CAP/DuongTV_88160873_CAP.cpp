#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned int t,n,m;
    cin >>t;
    for(int i =0;i<t;i++){
	
    n<=100;
    m<=100;
    cin >> n >>m;
    unsigned int a[100],b[100],c[100];
    for(int i=0; i<n;i++){
    	cin >> a[i];
    	
	}
	int d=0,e=0;
    for(int j=0;j<m;j++){
    	cin >> b[j];
    	if(j>=1){
    		for(int d=0;d<j;d++){
    			if(b[j]==b[d])
    			{
				
//				cout << "gg";
				e=e+1;
    			break;
				}
    		
			}
			if(e<1)
			
			c[j]=b[j];
    			
		}
	}
	c[0]=b[0];
	int count=0;
//	cout << d;
//	cout << e;
//	ind d=0;
   
		for(int i=0; i<m-e;i++){
//			cout << c[0];
    		for(int j=0;j<n;j++){
    			if(c[i]==a[j])
    			{
    			count++;
    			
    			break;
				}
			}
		}
	
	cout<< count;
	}
    return 0;
}
