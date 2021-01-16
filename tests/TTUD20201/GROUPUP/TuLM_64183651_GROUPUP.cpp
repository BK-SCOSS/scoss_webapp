#include <iostream>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int T;
	cin>>T;
	while(T>0) {
		int n;
		cin>>n;
		int time=0;
		int *b= new int[n];
		for (int i=0; i<n; ++i) cin>>b[i];
		while(n!=1) {
//			int m=(n+1)/2;
			int temp=0;
			
			if (n%2==0) {
				for (int i=0; i<n/2; ++i) {
					b[i] = b[2*i]+b[2*i+1];
					temp=max(temp,b[i]);
				}
				n=n/2;
			}
			else {
				for (int i=0; i<n/2; ++i) {
					b[i] = b[2*i]+b[2*i+1];
					temp=max(temp,b[i]);
				}
				b[(n+1)/2-1]=b[n-1];
				n=(n+1)/2;
			}
			
			time+=temp;
		}
		cout<<time<<endl;
		delete [] b;
		T--;
	}
	return 0;
}
