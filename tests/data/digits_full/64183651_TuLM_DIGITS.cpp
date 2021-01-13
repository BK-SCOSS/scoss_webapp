#include <iostream>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int* d= new int[7];
bool* choose=new bool[10];
unsigned long long count;
int n;
int sum;

int Try(int k) {
	for (int i=0;i<10;++i) {
		if ((k>=5)&&(i==0)) continue;
		
		if (!choose[i]) {
//			cout<<k<<" "<<i<<endl;
			d[k]=i;
			choose[i]=true;
			
			if(k==6) {
				sum=2*d[0]+10*d[1]+100*(d[2]+d[3])+1000*(d[4]+d[5])+10010*d[6];
				
//				for (int j=0;j<8;j++) cout<<d[j]<<" ";
//				cout<<sum<<endl;
				
				if (sum==n) {
//					for (int j=0;j<8;j++) cout<<d[j]<<" ";
//					cout<<endl;
					count++;
				}
				
				if (sum>=n) {
					choose[i]=false;
					break;
				}
			}
			else Try(k+1);
			
			choose[i]=false;
		}
	}	
}

int main(int argc, char** argv) {
	int T;		
	cin>>T;	
	while(T>0) {	
		cin>>n;
		count=0;
		if ((n%2==0)&&(n<=106224)) {
			for (int i=0;i<10;++i) choose[i]=false;
			
			d[0]=(n%10)/2;
			choose[d[0]]=true;
			Try(1);
			choose[d[0]]=false;
			
			d[0]=(n%10)/2+5;
			choose[d[0]]=true;
			Try(1);
			choose[d[0]]=false;
		}
		cout<<count<<endl;
		T--;
	}
	return 0;
}
