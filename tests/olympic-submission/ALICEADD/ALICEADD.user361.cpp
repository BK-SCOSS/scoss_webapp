#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int numData;
    cin >> numData;
    
    int sum[numData];
    for (int i = 0; i < numData; i++){
    	int a, b;
    	cin >> a >> b;
    	sum[i] = a + b;
	}
	
	for (int i = 0; i < numData; i++){
		cout << sum[i] << endl;
	}
}
