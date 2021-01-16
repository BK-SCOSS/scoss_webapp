#include<iostream>
using namespace std;

int n;
int *a, f[200];

int cbi() {
		cin>>n;
		a=new int[n+1];
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
}

int sum() {
int result = 1;
for (int i=1; i<=n; i++) {
    f[i] = 0;
    for (int j=0; j<i; j++) if (a[j]+1 == a[i]) {
        f[i] = max(f[i], f[j] + 1);
    }
    result = max(result, f[i]);
}
return result;
}
int main() {
	int T;
	cin>>T;
	while(T--) {
	    cbi();
           cout << sum() << endl;
         }
}
