#include <iostream>
#include <stdio.h>
#include <math.h>  

using namespace std;

void cntdiv(int k) {
	int t =  k*(k+1)*(k+2);
	long t2 = t*t;
	int d = 0;
	for (int i = 4; i<t; i++){
		if ((t2 % i == 0) && (t % i != 0)) {
		   d += 1;
	}
	}	   
	printf("%d\n",d);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
    	cin >> a[i];
   	for (int i=0; i<n; i++){
   		cntdiv(a[i]);
}
    return 0;
}
