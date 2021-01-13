#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int* s = new int [n];
    int* d = new int [n];
    int* r = new int [n];
    for (int i=0; i<n; i++) cin >> s[i] >> d[i] >> r[i];
    
    //set up
	int** a = new int *[n];
	int *p = new int [n*n];
	for (int i=0; i<n; i++) {
		a[i] = p;
		p += n;
	}
	
	int** b = new int *[n];
	int *q = new int [n*n];
	for (int i=0; i<n; i++) {
		b[i] = q;
		q += n;
	}
	
    //sap xep
    int* index = new int [n];
    for (int i=0; i<n; i++) index[i] = i;
    
    int temp;
    for (int i=0; i<n-1; i++) {
    	for (int j=i; j<n; j++) {
    		if (s[index[i]] > s[index[j]]) {
    			temp = index[i];
    			index[i] = index[j];
    			index[j] = temp;
			}
		}
	}
	for (int i=0; i<n; i++) {
		a[i][i] = r[index[i]];
		b[i][i] = i;
	}
	
	// quy hoach dong
	for (int j=1; j<n; j++) {
		for (int i=0; i<j; i++) {
			if (s[index[j]] >= (s[index[b[i][j-1]]] + d[index[b[i][j-1]]] +k)) {
				a[i][j] = a[i][j-1] + r[index[j]];
				b[i][j] = j;
			}
			else {
				a[i][j] = a[i][j-1];
				b[i][j] = b[i][j-1];
			}
		}
	}

	int max = a[0][n-1];
	for (int i=0; i<n; i++) {
		if (a[i][n-1] > max) max = a[i][n-1];
	}
	printf("%d",max);
	return 0;
}
