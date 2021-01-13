#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
    unsigned long long int a[10], b[10];
    for (int i=0; i<t; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i=0; i<t; i++) {
		cout << a[i]+b[i] << "\n";
	}
	return 0;
}
