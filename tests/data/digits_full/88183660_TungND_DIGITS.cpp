#include<iostream>
using namespace std;

int T,N,count;
int dem();

int main(){
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> N;
		if (N%2!=0) count = 0;
		else if (N<=11000) count =0;
		else if (N> 107000) count =0;
		else {
			count = dem();
		}
	}
	cout<<count;
	return 0;
}

int dem(){
	count =0;
	int h,u,s,t,o,i,c;
	int tong;
	for(s=1;s<=9;h++){
		for(o=0;o<=9;o++){
			if(o!=s){
				for(h=1;h<=9;h++)
				if((h!=s)&&(h!=o)){
					for(i=0;i<=9;i++){
						if((i!=s)&&(i!=o)&&(i!=h)){
							for(u=0;u<=9;u++){
								if((u!=s)&&(u!=o)&&(u!=h)&&(u!=i)){
									for(c=0;c<=9;c++){
										if((c!=s)&&(c!=o)&&(c!=h)&&(c!=i)&&(c!=u)) {
											for(t=0;t<=9;t++){
												if((t!=s)&&(t!=o)&&(t!=h)&&(t!=i)&&(t!=u)&&(t!=c)){
													tong = s*1e4 + (h+o)*1e3 + (u+i)*100 + (c+s)*10 + 2*t;
													if(tong==N)count++; 
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return count;
}

