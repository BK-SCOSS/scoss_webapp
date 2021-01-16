#include <iostream>
#include <stdlib.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int T;
	cin>>T;
	while(T>0) {
		int n,m;
		cin>>n;
		int* a = new int[n];		
		for (int i=0; i<n;) {
			cin>>a[i];
			int j=0;
			for (;j<i;++j) {
				if (a[i]==a[j]) break;
			}
			if (j==i) ++i;
			else n--;
		}
		
		cin>>m;
		int* b = new int[m];
		for (int i=0; i<m;) {
			cin>>b[i];
			int j=0;
			for (;j<i;++j) {
				if (b[i]==b[j]) break;
			}
			if (j==i) ++i;
			else m--;
		}
		
		int count=0;
		
		
		for (int i=0; i<n; ++i) {
			for (int j=0;j<m; ++j) {
				if (a[i]==b[j]) {
					count++;
					break;
				}
			}
		}
//		cout<<n<<" "<<m<<" "<<count<<endl;
//		for (int i=0; i<n; ++i) cout<<a[i]<<" ";
//		for (int i=0; i<m; ++i) cout<<b[i]<<" ";
		cout<<count<<endl;
		delete [] a;
		delete [] b;
		T--;
	}
	return 0;
}

