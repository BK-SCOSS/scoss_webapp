#include <iostream> 
using namespace std;
int dem(int n){
	int dem=0,t;
	t=n*(n+1)*(n+2);
	int k=t;
	t=t*t;
	for (int i=1; i<k; i++) if ((t%i==0)&(k%i!=0)) dem++;
	return dem;
}
int main(){
	int q, n;
	cin >> q;
	for (int i=0; i<q; i++){
		cin >> n;
		cout << dem(n) << endl;
	}
	return 0;
}
