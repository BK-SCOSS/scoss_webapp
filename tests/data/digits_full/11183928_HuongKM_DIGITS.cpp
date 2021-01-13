#include<bits/stdc++.h>
using namespace std;

int h,u,s,t,o,i,c,n,T;
int mang[51];
int main(){
	cin >> T;
	
	for(int k=0;k<T;k++){
		cin >> mang[k];
	}
	for(int k=0;k<T;k++){
		int kq=0;
		for(h=1;h<=9;h++){
			for(u=0;u<=9;u++){
				if(u==h) continue;
				else{
					for(s=1;s<=9;s++){
						if(s==u || s==h) continue;
						else{
							for(t=0;t<=9;t++)
							for(o=0;o<=9;o++)
							for(i=0;i<=9;i++)
							for(c=0;c<=9;c++){
								if((h*1000+u*100+s*10+t+s*10000+o*1000+i*100+c*10+t)==mang[k] && 
									h!=u && h!=s && h!=t && h!=o && h!=i && h!=c &&
									u!=s && u!=t && u!=o && u!=i && u!=c && s!=t &&
									s!=o && s!=i && s!=c && t!=o && t!=i && t!=c &&
									o!=i && o!=c && i!=c)
									kq++;
							}
						}
					}
				}
			}
		}
		
		
		
		
		
		cout << kq << endl;
			
	}
}
