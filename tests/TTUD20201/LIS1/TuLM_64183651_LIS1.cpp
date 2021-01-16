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
		
		int * a= new int[n];
		for (int i=0; i<n; ++i) scanf("%d", a+i);
		
		int *e =new int[n];
		e[0]=1;
		int res=1;
//		pre[0]=pre[1]=0;
		
		for (int i=1; i<n; ++i) {
			e[i]=1;
			for (int j=i-1; j>=0; --j) {
				if (a[j]+1 == a[i]) {
					e[i]=e[j]+1;
					break;
				}
				else if (a[j] == a[i]) {
					e[i]=e[j];
					break;
				}
			}
			res=max(res,e[i]);
		}
		cout<<res<<endl;
		delete [] a;
		delete [] e;
		T--;
	}
	return 0;
}
