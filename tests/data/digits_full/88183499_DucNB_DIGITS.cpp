#include<iostream>

using namespace std;

int H,U,S,T,O,I,C;


int main(){
	int T;
	cin>>T;
	int a[T];
	for(int i=0;i<T;i++){
		cin>>a[i];
	}
	int count[T];
	for(int x=0;x<T;x++){
		count[x]=0;
		if(a[x]<10000) continue;
		for(int h=1;h<=9;h++)
			for (int u=0;u<=9;u++)
				for(int s=1;s<=9;s++)
					for(int t=0;t<=9;t++)
						for(int o=0;o<=9;o++)
							for(int i=0;i<=9;i++)
								for(int c=0;c<=9;c++)
									{
										int val = h*1000+u*100+s*10+t+s*10000+o*1000+i*100+c*10+t;
										if(val==a[x]&&(h!=u)&&(h!=s)&&(h!=t)&&(h!=o)&&(h!=c)&&(h!=i)
										&&(u!=s)&&(u!=t)&&(u!=o)&&(u!=i)&&(u!=c)&&(u!=h)&&(s!=t)&&(s!=o)&&(s!=i)
										&&(s!=c)&&(t!=o)&&(t!=i)&&(t!=c)&&(o!=i)&&(o!=c)&&(i!=c))
											count[x]++;
									}
	}
	for(int x=0;x<T;x++) cout<<count[x]<<endl;
}
