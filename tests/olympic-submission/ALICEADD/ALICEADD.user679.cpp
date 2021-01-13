#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b[a], c[a];
	for(int i=0;i<a;i++)
		cin >> b[i] >> c[i];
	for(int i=0;i<a;i++)
		cout << b[i] + c[i] << endl;
	return 0;
}
