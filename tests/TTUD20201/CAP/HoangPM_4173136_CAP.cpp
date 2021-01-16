
#include<iostream>
using namespace std;

int n;
int m;
int *a;
int *b;
int c[200];

int cbi() {
		cin>>n;
		a=new int[n+1];
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		cin>>m;
		b=new int[m+1];
		for(int i=1;i<=m;i++) {
			cin>>b[i];
		}
}

int sum() {
    int temp = 0;
	 for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(a[i]==b[j]) {
				   c[i]=a[i];
				   temp++;
			    }
			}
		}
		cout << temp << endl;
}
int main() {
	int T;
	cin>>T;
	while(T--) {
	    cbi();
            sum();
         }
}
