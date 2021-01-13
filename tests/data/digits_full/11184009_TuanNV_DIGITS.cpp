#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,x;
	int h,u,s,t,o,i,c;
	cin >> x;
	int a[x];
	for(int j=0;j<x;j++){
		cin >> n;
			int q = 0;	
	
	
	for(h = 1; h < 10; h++){
		for(u = 0; u < 10; u++){
			for(s = 1; s < 10; s++){
				for(t = 0; t < 10; t++){
					for(o = 0; o < 10; o++){
						for(i = 0; i< 10; i++){
							for(c = 0; c < 10; c++){
								if((1000*h + 100*u +10*s +t + 10000*s+1000*o+100*i +10*c +t) == n && 
									h!=u && h!=s &&h!=t && h!=o && h!=i && h!=c && u!=s && u!=t
									&& u!=o && u!=i &&u!=c && s!=t && s!=o && s!=i && s!=c &&
									t!=o && t!=i && t!=c && o!=i && o!=c && i!=c){ 
									q++;
								}
							}
						}
					}
				}
			}
		}
	}
	
	a[j]=q;}
	for(int j=0;j<x;j++){
		cout << a[j] <<  endl;
	}
	
	return 0;
}
