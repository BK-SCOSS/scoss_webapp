#include <iostream>
using namespace std;
int main(){
	int n;
	do{
	cin >> n;
	}
	while(n<=0 || n>10);
	
	int i,a,b;
	for(i=0;i<n;i++){
		cin >> a >> b;
		cout << a+b << endl;
	}
	
	return 0;
}
